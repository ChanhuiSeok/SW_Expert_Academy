#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

/*

������ ��Ȯ�ϰ� ���� ������ ���� ������..
�ʹ� ���� �ð��� ���ȴ�...

�迭�� ��ȣ���� ���� ����Ʈ�� ������ ���� ���̴�..

�̰Ŵ� ����Ʈ�� �ִ��� ���� �Ծ��� �� �� ������ ����ϴ°ǵ�

���� �迭�� ������ ��ȣ���� ����Ʈ�� ������ �߸� �����ϰ�
�� �յ��� �ִ밡 �� ���� �׵θ� ĭ�� ������ ����ϴϱ� �ڲ� Ʋ�ȴ�..
.
.
.
...
.
..%^%^^

*/


using namespace std;
int N;

// ������ �Ʒ��� 0��, ������ ���� 1��, ���� �Ʒ��� 2��, ���� ���� 3��
int dy[4] = { 1,-1,1,-1 };
int dx[4] = { 1,1,-1,-1 };
int dessert[101];
int maxCnt = -100, sum = 0, maxSum = -100;
int arr[21][21];
// prev_dir ���� :
// 0�̸� ���� ��ġ�� ���� ������ �°�,// 1�̸� ������ ������ �� ��,
// 2�� ������ �Ʒ����� �� ��,// 3�̸� ���� �Ʒ����� �� ���̴�.
void dfs(int prev_dir, int start_y, int start_x, int y, int x, int path, int sum, int corner) {
	if (corner >= 5)
		return;

	if (prev_dir == 0) { // ���� ������ ���� ��
		dessert[arr[y][x]] = 1;

		// ������ �Ʒ��� ���ų�, ���� �Ʒ��� �� �� �ִ�.
		for (int i = 0; i < 4; i = i + 2) {
			int ty = y + dy[i];
			int tx = x + dx[i];

			// ���� �� ���� ó�� ��ġ�� �����ϸ� ����
			if ((ty == start_y && tx == start_x && (corner == 2 && path >= 3)) ||
				(ty == start_y && tx == start_x && (corner == 3 && path >= 3))) {
				sum += arr[start_y][start_x];
				if (maxCnt < path) {
					maxCnt = path;
				}
				return;
			}

			// ��� ���� ���� �ְ�, ������ �� ���� ���� path ��ο� ���� ���� �߰��ϱ�
			if (ty <= N && ty >= 1 && tx <= N && tx >= 1 && dessert[arr[ty][tx]] == 0) {

				if (i == 0) { // ���� ������ ���� �� ������ �Ʒ��� ���ߴٸ�,
					dessert[arr[ty][tx]] = 1;
					dfs(0, start_y, start_x, ty, tx, path + 1, sum + arr[ty][tx], corner); // ���� ��ġ ���忡���� ���� ���̴�.
					dessert[arr[ty][tx]] = 0;
				}
				else if (i == 2) { // ���� ������ ���� �� ���� �Ʒ��� ���ߴٸ�,
					// ���� �� ��ġ�� ������ �𼭸��̴�.
					dessert[arr[ty][tx]] = 1;
					dfs(1, start_y, start_x, ty, tx, path + 1, sum + arr[ty][tx], corner + 1); // ���� ��ġ ���忡���� ������ ���̴�.
					dessert[arr[ty][tx]] = 0;
				}
			}
		}
		dessert[arr[y][x]] = 0;
	}

	else if (prev_dir == 1) { // ������ ������ ���� ��
		dessert[arr[y][x]] = 1;

		// ���� �� Ȥ�� ���� �Ʒ��� �� �� �ִ�.
		for (int i = 2; i < 4; i++) {
			int ty = y + dy[i];
			int tx = x + dx[i];

			// ���� �� ���� ó�� ��ġ�� �����ϸ� ����
			if ((ty == start_y && tx == start_x && (corner == 2 && path >= 3)) ||
				(ty == start_y && tx == start_x && (corner == 3 && path >= 3))) {
				sum += arr[start_y][start_x];
				if (maxCnt < path) {
					maxCnt = path;
				}
				return;
			}

			// ��� ���� ���� �ְ�, ������ �� ���� ���� path ��ο� ���� ���� �߰��ϱ�
			if (ty <= N && ty >= 1 && tx <= N && tx >= 1 && dessert[arr[ty][tx]] == 0) {

				if (i == 2) { // ������ ������ �ͼ� ���� �Ʒ��� ���ߴٸ�, ���� ��ġ ���忡���� ������ ���̴�.
					dessert[arr[ty][tx]] = 1;
					dfs(1, start_y, start_x, ty, tx, path + 1, sum + arr[ty][tx], corner);
					dessert[arr[ty][tx]] = 0;
				}
				else if (i == 3) { // ������ ������ �ͼ� ���� ���� ���ߴٸ�, ���� �� ��ġ�� �Ʒ��� �𼭸��̴�.
					// ���� ��ġ ���忡���� ������ �Ʒ��̴�.
					dessert[arr[ty][tx]] = 1;
					dfs(2, start_y, start_x, ty, tx, path + 1, sum + arr[ty][tx], corner + 1);
					dessert[arr[ty][tx]] = 0;
				}
			}
		}
		dessert[arr[y][x]] = 0;
	}

	else if (prev_dir == 2) { // ������ �Ʒ����� ���� ��
		dessert[arr[y][x]] = 1;

		// ���� �� Ȥ�� ������ ���� �� �� �ִ�.
		for (int i = 1; i < 4; i = i + 2) {
			int ty = y + dy[i];
			int tx = x + dx[i];

			// ���� �� ���� ó�� ��ġ�� �����ϸ� ����
			if ((ty == start_y && tx == start_x && (corner == 2 && path >= 3)) ||
				(ty == start_y && tx == start_x && (corner == 3 && path >= 3))) {
				sum += arr[start_y][start_x];
				if (maxCnt < path) {
					maxCnt = path;
				}
				return;
			}

			// ��� ���� ���� �ְ�, ������ �� ���� ���� path ��ο� ���� ���� �߰��ϱ�
			if (ty <= N && ty >= 1 && tx <= N && tx >= 1 && dessert[arr[ty][tx]] == 0) {

				if (i == 1) { // ������ �Ʒ����� ���� �� ������ ���� ����, ���� ��ġ ���忡�� ���� �Ʒ��̴�.
					// �׸��� �ڳʰ� �ȴ�.
					dessert[arr[ty][tx]] = 1;
					dfs(3, start_y, start_x, ty, tx, path + 1, sum + arr[ty][tx], corner + 1);
					dessert[arr[ty][tx]] = 0;
				}
				else if (i == 3) { // ������ �Ʒ����� ���� �� ���� ���� ����, ���� ��ġ ���忡�� ������ �Ʒ��̴�.
					dessert[arr[ty][tx]] = 1;
					dfs(2, start_y, start_x, ty, tx, path + 1, sum + arr[ty][tx], corner);
					dessert[arr[ty][tx]] = 0;
				}
			}
		}
		dessert[arr[y][x]] = 0;
	}

	else if (prev_dir == 3) { // ���� �Ʒ����� ���� ��
		dessert[arr[y][x]] = 1;

		// ������ �� Ȥ�� ������ �Ʒ��� �� �� �ִ�.
		for (int i = 0; i < 2; i++) {
			int ty = y + dy[i];
			int tx = x + dx[i];

			// ���� �� ���� ó�� ��ġ�� �����ϸ� ����
			if ((ty == start_y && tx == start_x && (corner == 2 && path >= 3)) ||
				(ty == start_y && tx == start_x && (corner == 3 && path >= 3))) {
				sum += arr[start_y][start_x];
				if (maxCnt < path) {
					maxCnt = path;
				}
				return;
			}

			// ��� ���� ���� �ְ�, ������ �� ���� ���� path ��ο� ���� ���� �߰��ϱ�
			if (ty <= N && ty >= 1 && tx <= N && tx >= 1 && dessert[arr[ty][tx]] == 0) {

				if (i == 0) { // ���� �Ʒ����� �ͼ� ������ �Ʒ��� ���ߴٸ�, ���� �� ��ġ�� �𼭸��̴�. ���� ��ġ ���忡���� ���� ���̴�.
					dessert[arr[ty][tx]] = 1;
					dfs(0, start_y, start_x, ty, tx, path + 1, sum + arr[ty][tx], corner + 1);
					dessert[arr[ty][tx]] = 0;
				}
				else if (i == 1) { // ���� �Ʒ����� �ͼ� ������ ���� ���ߴٸ�, ���� ��ġ ���忡���� ���� �Ʒ��̴�.
					dessert[arr[ty][tx]] = 1;
					dfs(3, start_y, start_x, ty, tx, path + 1, sum + arr[ty][tx], corner);
					dessert[arr[ty][tx]] = 0;
				}
			}
		}
		dessert[arr[y][x]] = 0;
	}

}

int main() {

	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		scanf("%d", &N);

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				scanf("%d", &arr[i][j]);
			}
		}

		for (int j = 1; j <= N - 2; j++) { // ������ �� �ִ� ���ȣ
			for (int k = 2; k <= N - 1; k++) { // ������ �� �� �ִ� ����ȣ
				dfs(0, j, k, j, k, 0, 0, 0);
			}
		}

		if (maxCnt != -100)
			printf("#%d %d\n", t, maxCnt + 1);

		else
			printf("#%d -1\n", t);

		maxCnt = -100;
		maxSum = -100;
	}

}