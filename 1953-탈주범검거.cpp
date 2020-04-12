#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

int arr[51][51];
int visit[51][51];
int place[51][51];
int N, M, R, C, L;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 }; // �����¿�
int place_cnt = 0;
int L_cnt = 0;

void findPath(int y, int x) {

	visit[y][x] = 1;

	//��,��,��,�� ��� ����. ��, ���� ĭ���� ������� ���ϸ� ����
	if (arr[y][x] == 1) {
		for (int i = 0; i < 4; i++) {
			int ty = y + dy[i];
			int tx = x + dx[i];

			// ���� �Ʒ��� ���� �� �� �������� ���� ���� ����
			if ((i == 0 && arr[ty][tx] != 3 && arr[ty][tx] != 4 && arr[ty][tx] != 7 && arr[ty][tx] != 0) ||
				(i == 1 && arr[ty][tx] != 3 && arr[ty][tx] != 5 && arr[ty][tx] != 6 && arr[ty][tx] != 0)) {
				// ��� ������ �����̸� �湮���� �ʾҴٸ�
				if (ty < N && ty >= 0 && tx < M && tx >= 0
					&& visit[ty][tx] != 1 && L_cnt < L-1) {

					visit[ty][tx] = 1; // �湮 ǥ�� ����
					place[ty][tx] = 1;
					L_cnt += 1; // �̵� �� �ѽð� ����

					findPath(ty, tx);

					visit[ty][tx] = 0; // ����
					L_cnt -= 1; // ����
				}
			}

			// �� ��� ������ �� �������� ���� ���� ����
			if ((i == 2 && arr[ty][tx] != 2 && arr[ty][tx] != 6 && arr[ty][tx] != 7 && arr[ty][tx] != 0) ||
				(i == 3 && arr[ty][tx] != 2 && arr[ty][tx] != 4 && arr[ty][tx] != 5 && arr[ty][tx] != 0)) {
				// ��� ������ �����̸� �湮���� �ʾҴٸ�
				if (ty < N && ty >= 0 && tx < M && tx >= 0
					&& visit[ty][tx] != 1 && L_cnt < L-1) {

					visit[ty][tx] = 1; // �湮 ǥ�� ����
					place[ty][tx] = 1;
					L_cnt += 1; // �̵� �� �ѽð� ����

					findPath(ty, tx);

					visit[ty][tx] = 0; // ����
					L_cnt -= 1; // ����
				}
			}

		}
	}
	// ��, �ϸ� ����
	else if (arr[y][x] == 2) {
		for (int i = 0; i < 2; i++) {
			int ty = y + dy[i];
			int tx = x + dx[i];

			// ��, �� ������ ������ ��, �� �������� ���� ����
			if ((i == 0 && arr[ty][tx] != 3 && arr[ty][tx] != 4 && arr[ty][tx] != 7 && arr[ty][tx] != 0)||
				(i == 1 && arr[ty][tx] != 3 && arr[ty][tx] != 5 && arr[ty][tx] != 6 && arr[ty][tx] != 0)){
				// ��� ������ �����̸� �湮���� �ʾҴٸ�
				if (ty < N && ty >= 0 && tx < M && tx >= 0
					&& visit[ty][tx] != 1 && L_cnt < L-1) {

					visit[ty][tx] = 1; // �湮 ǥ�� ����
					place[ty][tx] = 1;
					L_cnt += 1; // �̵� �� �ѽð� ����

					findPath(ty, tx);

					visit[ty][tx] = 0; // ����
					L_cnt -= 1; // ����
				}
			}
		}
	}
	// ��, �� ����
	else if (arr[y][x] == 3) {

		for (int i = 2; i < 4; i++) {
			int ty = y + dy[i];
			int tx = x + dx[i];

			// ��, �� ������ ������ ��, �� �������� ���� ����
			if ((i == 2 && arr[ty][tx] != 2 && arr[ty][tx] != 6 && arr[ty][tx] != 7 && arr[ty][tx] != 0)||
				(i == 3 && arr[ty][tx] != 2 && arr[ty][tx] != 5 && arr[ty][tx] != 4 && arr[ty][tx] != 0)){
				// ��� ������ �����̸� �湮���� �ʾҴٸ�
				if (ty < N && ty >= 0 && tx < M && tx >= 0
					&& visit[ty][tx] != 1 && L_cnt < L-1) {

					visit[ty][tx] = 1; // �湮 ǥ�� ����
					place[ty][tx] = 1;
					L_cnt += 1; // �̵� �� �ѽð� ����

					findPath(ty, tx);

					visit[ty][tx] = 0; // ����
					L_cnt -= 1; // ����
				}
			}
		}

	}
	// ��, �� ����
	else if (arr[y][x] == 4) {

		for (int i = 0; i < 4; i = i + 3) {
			int ty = y + dy[i];
			int tx = x + dx[i];

			// ���ΰ� �� ���� �� ���η� ���� ������ �ȵ�
			// Ȥ�� ���������� �� �� ���� �� ���η� ���������� �� ��
			if ((i == 0 && arr[ty][tx] != 3 && arr[ty][tx] != 4 && arr[ty][tx] != 7 && arr[ty][tx] != 0) ||
				(i == 3 && arr[ty][tx] != 2 && arr[ty][tx] != 5 && arr[ty][tx] != 4 && arr[ty][tx] != 0)) {
				// ��� ������ �����̸� �湮���� �ʾҴٸ�
				if (ty < N && ty >= 0 && tx < M && tx >= 0
					&& visit[ty][tx] != 1 && L_cnt < L-1) {

					visit[ty][tx] = 1; // �湮 ǥ�� ����
					place[ty][tx] = 1;
					L_cnt += 1; // �̵� �� �ѽð� ����

					findPath(ty, tx);

					visit[ty][tx] = 0; // ����
					L_cnt -= 1; // ����
				}
			}
		}

	}
	// ��, �� ����
	else if (arr[y][x] == 5) {

		for (int i = 1; i < 4; i = i + 2) {
			int ty = y + dy[i];
			int tx = x + dx[i];

			// �Ʒ��ΰ� �� ���� �� ���η� ���� ������ �ȵ�
			// Ȥ�� ���������� �� �� ���� �� ���η� ���������� �� ��
			if ((i == 1 && arr[ty][tx] != 3 && arr[ty][tx] != 5 && arr[ty][tx] != 6 && arr[ty][tx] != 0) ||
				(i == 3 && arr[ty][tx] != 2 && arr[ty][tx] != 4 && arr[ty][tx] != 5 && arr[ty][tx] != 0)) {
				// ��� ������ �����̸� �湮���� �ʾҴٸ�
				if (ty < N && ty >= 0 && tx < M && tx >= 0
					&& visit[ty][tx] != 1 && L_cnt < L-1) {

					visit[ty][tx] = 1; // �湮 ǥ�� ����
					place[ty][tx] = 1;
					L_cnt += 1; // �̵� �� �ѽð� ����

					findPath(ty, tx);

					visit[ty][tx] = 0; // ����
					L_cnt -= 1; // ����
				}
			}
		}

	}
	// ��, �� ����
	else if (arr[y][x] == 6) {

		for (int i = 1; i < 3; i++) {
			int ty = y + dy[i];
			int tx = x + dx[i];

			// �Ʒ��ΰ� �� ���� �� ���η� ���� ������ �ȵ�
			// Ȥ�� �������� �� �� ���� �� ���η� ���������� �� ��
			if ((i == 1 && arr[ty][tx] != 3 && arr[ty][tx] != 5 && arr[ty][tx] != 6 && arr[ty][tx] != 0) ||
				(i == 2 && arr[ty][tx] != 2 && arr[ty][tx] != 6 && arr[ty][tx] != 7 && arr[ty][tx] != 0)) {
				// ��� ������ �����̸� �湮���� �ʾҴٸ�
				if (ty < N && ty >= 0 && tx < M && tx >= 0
					&& visit[ty][tx] != 1 && L_cnt < L-1) {

					visit[ty][tx] = 1; // �湮 ǥ�� ����
					place[ty][tx] = 1;
					L_cnt += 1; // �̵� �� �ѽð� ����

					findPath(ty, tx);

					visit[ty][tx] = 0; // ����
					L_cnt -= 1; // ����
				}
			}
		}

	}
	// ��, �� ����
	else if (arr[y][x] == 7) {

		for (int i = 0; i < 4; i=i+2) {
			int ty = y + dy[i];
			int tx = x + dx[i];

			// ���ΰ� �� ���� �� ���η� ���� ������ �ȵ�
			// Ȥ�� �������� �� �� ���� �� ���η� ���������� �� ��
			if ((i == 0 && arr[ty][tx] != 3 && arr[ty][tx] != 4 && arr[ty][tx] != 7 && arr[ty][tx] != 0) ||
				(i == 2 && arr[ty][tx] != 2 && arr[ty][tx] != 6 && arr[ty][tx] != 7 && arr[ty][tx] != 0)) {
				// ��� ������ �����̸� �湮���� �ʾҴٸ�
				if (ty < N && ty >= 0 && tx < M && tx >= 0
					&& visit[ty][tx] != 1 && L_cnt < L-1) {

					visit[ty][tx] = 1; // �湮 ǥ�� ����
					place[ty][tx] = 1;
					L_cnt += 1; // �̵� �� �ѽð� ����

					findPath(ty, tx);

					visit[ty][tx] = 0; // ����
					L_cnt -= 1; // ����
				}
			}
		}
	}


}


int main() {

	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {

		scanf("%d %d %d %d %d", &N, &M, &R, &C, &L);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf("%d", &arr[i][j]);
			}
		}


		findPath(R, C);
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (place[i][j] == 1) {
					place_cnt += 1;
					place[i][j] = 0;
				}
			}
		}


		printf("#%d %d", t, place_cnt+1);

		place_cnt = 0;
		visit[R][C] = 0;
		L_cnt = 0;
	}

}