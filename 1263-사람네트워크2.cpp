#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000001
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int CC[1001];
int dist[1001];

priority_queue < pair<int, int>, vector <pair<int, int> >, greater<pair<int, int> > >PQ;

int main() {

	int T, N;
	int input, startV;
	int idx = 0, length = 0;
	int p_vertex, p_cost;
	int min = 999999;

	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {

		scanf("%d", &N);
		// dist 배열을 처음엔 MAX로 초기화
		for (int i = 0; i < N; i++) {
			dist[i] = MAX;
		}
		// pair -> (cost, vertex) -> 이 문제는 cost = 1로 동일
		vector <pair<int, int> > graph[1001];

		// 인접행렬 입력받기
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &input);
				if (input == 1) {
					graph[i].push_back(make_pair(1, j));
				}
			}
		}

		for (int idx = 0; idx < N; idx++) {

			startV = idx; // idx = 0에서 시작
			dist[startV] = 0;

			// 가장 먼저, 시작점의 cost(1)과 시작점 번호를 PQ에 푸쉬
			PQ.push(make_pair(dist[startV], startV));

			// 우선순위 큐가 빌 때까지 반복
			while (!PQ.empty()) {
				p_cost = PQ.top().first;
				p_vertex = PQ.top().second;

				PQ.pop();

				for (int i = 0; i < graph[p_vertex].size(); i++) {
					// 시작에서 현재까지 오는 거리 + 현재에서 특정 노드까지 가는 거리가
					// dist 배열의 특정 노드 값보다 짧다면 갱신
					if (dist[graph[p_vertex][i].second] > p_cost + graph[p_vertex][i].first) {
						dist[graph[p_vertex][i].second] = p_cost + graph[p_vertex][i].first;
						PQ.push(make_pair(p_cost + graph[p_vertex][i].first, graph[p_vertex][i].second));
					}
				}
			}

			// 초기화 (모든 정점에 대해 CC 배열을 채워야 하므로)
			for (int k = 0; k < N; k++) 
				length = length + dist[k];
			
			for (int k = 0; k < N; k++) 
				dist[k] = MAX;
			
			CC[idx] = length;
			length = 0;
		}

		for (int j = 0; j < N; j++) {
			if (min >= CC[j])
				min = CC[j];
		}

		printf("#%d %d\n",t,min);

		min = 9999999;
	}

}