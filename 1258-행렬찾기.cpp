#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

int arr[101][101];
int visit[101][101];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

int N, mtx_size, row = 0, col = 0;
// sorting ���� compare �Լ�
int compare(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second)
		return a.first > b.first;
	return a.second < b.second;
}

void dfs(int y, int x) {
	int ty, tx;
	int tempTy, tempTx;

	// dfs�� ȣ������ ���� 0�� �ƴϰ�, �湮 ���� ���̹Ƿ� �κ� ��� ������ �غ��Ѵ�.
	mtx_size = mtx_size + 1; // 0�� �ƴ� ù ��Ҹ� �湮�����Ƿ� 1 �������� �ش�.
	visit[y][x] = true; // �湮�����Ƿ� �湮�ߴٴ� ǥ�ø� �Ѵ�.

	tempTx = x;

	// ������ �����¿츦 �� ����.
	for (int i = 0; i < 4; i++) {
		ty = y + dy[i]; // ��
		tx = x + dx[i]; // ��
		// ������ �����Ų ��... ���� �ƴϰ�, �湮���� �ʾ��� ���
		if (tx >= 0 && tx < N && ty >= 0 && ty < N
			&& arr[ty][tx] != 0 && visit[ty][tx] == false) {
			if (tx == tempTx + 1)
				col = col + 1;

			dfs(ty, tx);
		}
	}
}

int main() {

	int test_case;
	int v_col, v_row, v_size;
	scanf("%d", &test_case);
	for (int T = 1; T <= 10; T++) {
		// �� ���� ����
		vector <pair<int, int>> v;
		// visit �迭 �ʱ�ȭ
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				visit[i][j] = false;
			}
		}
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &arr[i][j]);
			}
		}
		// 2���� �迭 arr�� ���� DFS Ž���ϱ�
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				// �迭 ���� 0�� �ƴϰ�, �湮�� ���� ���� �� (i�� j��)
				if (arr[i][j] != 0 && visit[i][j] == false) {
					dfs(i, j);
					// ��� ���� �� �� �κ� ��Ŀ� ���� ������ ���Ϳ� Ǫ���Ѵ�.
					v.push_back(make_pair(col + 1, mtx_size));
				}
				// �ʱ�ȭ
				mtx_size = 0; col = 0;
			}
		}
		// ���͸� size �������� ����
		sort(v.begin(), v.end(), compare);
		printf("#%d %d ", T, v.size());
		for (int i = 0; i < v.size(); i++) {
			v_col = v[i].first;
			v_size = v[i].second;
			v_row = v_size / v_col;
			printf("%d %d ", v_row, v_col);
		}
		printf("\n");
	}
	return 0;
}