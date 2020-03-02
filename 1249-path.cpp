#define _CRT_SECURE_NO_WARNINGS
#define INF 999999
#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;

int arr[101][101];
int depArr[101][101];

// 상, 하, 좌, 우
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

int main() {

    int test_case, N, idx_x, idx_y;
    int path;
    queue<pair<int, int>> q;

    scanf("%d", &test_case);
    for (int T = 1; T <= 10; T++) {
        scanf("%d", &N);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%1d", &arr[i][j]);
                depArr[i][j] = INF;
            }
        }
        depArr[0][0] = 0;
        // 여기까지 하면 자료 입력받기 완료
        // 맨 처음 칸에 대한 계산을 위해, dep

        q.push(make_pair(0, 0));

        while (q.size()) {
            idx_x = q.front().first;
            idx_y = q.front().second;
            q.pop();

            /* 상, 하, 좌, 우 좌표를 큐에 넣기 */
            for (int i = 0; i < 4; i++) {
                int next_x = idx_x + dx[i];
                int next_y = idx_y + dy[i];

                if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N)
                    continue;

                // 경로의 합 (다음에 갈 곳의 값이 
                if (depArr[next_x][next_y] > depArr[idx_x][idx_y] + arr[next_x][next_y]) {
                    depArr[next_x][next_y] = depArr[idx_x][idx_y] + arr[next_x][next_y];
                    q.push(make_pair(next_x, next_y));
                }
            }
        }
        // 최종적으로 맨 마지막 칸에 있는 값을 출력하면 답이 된다.
        printf("#%d %d\n", T, depArr[N - 1][N - 1]);
    }

}