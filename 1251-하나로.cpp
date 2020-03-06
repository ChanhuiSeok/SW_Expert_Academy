#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int parent[1001];
int ranks[1001];

typedef struct xys {
	long long n1;
	long long n2;
	double dist;
}xy;

bool compare(xy a, xy b) {
	return a.dist < b.dist;
}

int find(int x) {
	if (parent[x] == x) {
		return x;
	}
	return parent[x] = find(parent[x]); // collapsing find (압축)
}

void UNION(int a, int b) {

	// 작은 쪽에 합하기 (b를 a에 합치기)
	a = find(a);
	b = find(b);

	if (a < b) {
		parent[b] = a;
	}
	else
		parent[a] = b;
}


int main() {

	int test_case;
	int N, X1, X2, Y1, Y2, node1, node2, idx;
	int count = 0;
	double temp;
	double E;
	double result = 0;

	scanf("%d", &test_case);

	for (int T = 1; T <= 10; T++) {
		vector <pair<int, int>> v;
		vector <xy> distance;
		int x[1001], y[1001];
		scanf("%d", &N);

		for (int i = 0; i < N; i++) 
			scanf("%d", &x[i]);
		
		for (int i = 0; i < N; i++) 
			scanf("%d", &y[i]);
		
		for (int i = 0; i < N; i++)
			v.push_back(make_pair(x[i],y[i]));

		scanf("%lf", &E);

		// 거리 계산하여 배열에 넣기
		for (int j = 0; j < N; j++) {
			X1 = v[j].first;
			Y1 = v[j].second;
			for (int k = j + 1; k < N; k++) {
				xy input;
				X2 = v[k].first;
				Y2 = v[k].second;

				temp = sqrt(double((X2 - X1) * (X2 - X1) + (Y2 - Y1) * (Y2 - Y1)));
				temp = temp * temp * E;
				input.n1 = j; input.n2 = k; input.dist = temp;

				distance.push_back(input);
			}
		}

		// 거리 벡터를 오름차순 정렬
		sort(distance.begin(), distance.end(), compare);


		// 크루스칼 알고리즘 진행
		// (1) parent 배열을 모두 자기 자신으로 초기화 및 랭크 배열 0으로 초기화
		for (int m = 0; m < N; m++) {
			parent[m] = m;
			ranks[m] = 0;
		}

		idx = 0;
		while(1) {
			node1 = distance[idx].n1;
			node2 = distance[idx].n2;

			node1 = find(node1);
			node2 = find(node2);

			// 두 노드의 부모 배열을 확인 -> 값이 다르면, 노드 번호가 작은 쪽에 union
			if (node1 != node2) {
				UNION(node1, node2);
				count++;
				result += distance[idx].dist;
				idx++;

				if (count == N-1) { // 정점수 -1 개만큼의 간선이 선택되면
					break;
				}
			}
			else {  // 같으면 스킵
				idx++;
				continue;
			}
		}

		printf("%f\n", result);

		// 초기화
		result = 0;
		count = 0;
		
	}

}