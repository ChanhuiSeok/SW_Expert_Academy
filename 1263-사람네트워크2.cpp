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
		// dist �迭�� ó���� MAX�� �ʱ�ȭ
		for (int i = 0; i < N; i++) {
			dist[i] = MAX;
		}
		// pair -> (cost, vertex) -> �� ������ cost = 1�� ����
		vector <pair<int, int> > graph[1001];

		// ������� �Է¹ޱ�
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &input);
				if (input == 1) {
					graph[i].push_back(make_pair(1, j));
				}
			}
		}

		for (int idx = 0; idx < N; idx++) {

			startV = idx; // idx = 0���� ����
			dist[startV] = 0;

			// ���� ����, �������� cost(1)�� ������ ��ȣ�� PQ�� Ǫ��
			PQ.push(make_pair(dist[startV], startV));

			// �켱���� ť�� �� ������ �ݺ�
			while (!PQ.empty()) {
				p_cost = PQ.top().first;
				p_vertex = PQ.top().second;

				PQ.pop();

				for (int i = 0; i < graph[p_vertex].size(); i++) {
					// ���ۿ��� ������� ���� �Ÿ� + ���翡�� Ư�� ������ ���� �Ÿ���
					// dist �迭�� Ư�� ��� ������ ª�ٸ� ����
					if (dist[graph[p_vertex][i].second] > p_cost + graph[p_vertex][i].first) {
						dist[graph[p_vertex][i].second] = p_cost + graph[p_vertex][i].first;
						PQ.push(make_pair(p_cost + graph[p_vertex][i].first, graph[p_vertex][i].second));
					}
				}
			}

			// �ʱ�ȭ (��� ������ ���� CC �迭�� ä���� �ϹǷ�)
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