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
	return parent[x] = find(parent[x]); // collapsing find (����)
}

void UNION(int a, int b) {

	// ���� �ʿ� ���ϱ� (b�� a�� ��ġ��)
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

		// �Ÿ� ����Ͽ� �迭�� �ֱ�
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

		// �Ÿ� ���͸� �������� ����
		sort(distance.begin(), distance.end(), compare);


		// ũ�罺Į �˰��� ����
		// (1) parent �迭�� ��� �ڱ� �ڽ����� �ʱ�ȭ �� ��ũ �迭 0���� �ʱ�ȭ
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

			// �� ����� �θ� �迭�� Ȯ�� -> ���� �ٸ���, ��� ��ȣ�� ���� �ʿ� union
			if (node1 != node2) {
				UNION(node1, node2);
				count++;
				result += distance[idx].dist;
				idx++;

				if (count == N-1) { // ������ -1 ����ŭ�� ������ ���õǸ�
					break;
				}
			}
			else {  // ������ ��ŵ
				idx++;
				continue;
			}
		}

		printf("%f\n", result);

		// �ʱ�ȭ
		result = 0;
		count = 0;
		
	}

}