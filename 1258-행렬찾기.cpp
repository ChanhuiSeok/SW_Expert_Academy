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
// sorting 위한 compare 함수
int compare(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second)
		return a.first > b.first;
	return a.second < b.second;
}

void dfs(int y, int x) {
	int ty, tx;
	int tempTy, tempTx;

	// dfs를 호출했을 때는 0이 아니고, 방문 안한 곳이므로 부분 행렬 정보를 준비한다.
	mtx_size = mtx_size + 1; // 0이 아닌 첫 요소를 방문했으므로 1 증가시켜 준다.
	visit[y][x] = true; // 방문했으므로 방문했다는 표시를 한다.

	tempTx = x;

	// 인접한 상하좌우를 다 본다.
	for (int i = 0; i < 4; i++) {
		ty = y + dy[i]; // 행
		tx = x + dx[i]; // 열
		// 방향을 변경시킨 뒤... 벽이 아니고, 방문하지 않았을 경우
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
		// 새 벡터 생성
		vector <pair<int, int>> v;
		// visit 배열 초기화
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
		// 2차원 배열 arr에 대해 DFS 탐색하기
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				// 배열 값이 0이 아니고, 방문한 적이 없을 때 (i행 j열)
				if (arr[i][j] != 0 && visit[i][j] == false) {
					dfs(i, j);
					// 모두 종료 시 이 부분 행렬에 대한 정보를 벡터에 푸쉬한다.
					v.push_back(make_pair(col + 1, mtx_size));
				}
				// 초기화
				mtx_size = 0; col = 0;
			}
		}
		// 벡터를 size 기준으로 정렬
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