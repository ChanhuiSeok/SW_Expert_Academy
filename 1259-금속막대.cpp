#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000001
#include <iostream>
#include <cstdio>
#include <list>
#include <vector>

using namespace std;

int main() {

	int test_case;
	int n, x, y;
	int inX, inY;
	int vdx = 0;
	list <pair<int, int>> li;
	vector <pair<int, int>> v;

	scanf("%d", &test_case);

	for (int T = 1; T <= test_case; T++) {

		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			scanf("%d %d", &x, &y);

			// 첫 번째일 경우
			if (li.empty()) {
				li.push_back(make_pair(x, y));
				continue;
			}

			// 리스트 맨 앞의 수나사와 금속막대의 암나사 크기가 같다면
			if (li.front().first == y) {
				li.push_front(make_pair(x, y));
			}
			// 리스트 맨 마지막의 암나사와 금속막대의 수나사 크기가 같다면
			else if (li.back().second == x) {
				li.push_back(make_pair(x, y));
			}
			else {
				v.push_back(make_pair(x, y));
			}
		}

		vector <pair<int, int>>::iterator v_iter;
		v_iter = v.begin();

		// 벡터가 빌 때까지 연결
		while (!v.empty()) {

			// 맨 뒤에 연결 가능 시
			if (v[vdx].first == li.back().second) {
				li.push_back(make_pair(v[vdx].first, v[vdx].second));
				v.erase(v.begin()+vdx);
				vdx = 0;
			}
			// 맨 앞에 연결 가능 시
			else if (v[vdx].second == li.front().first) {
				li.push_front(make_pair(v[vdx].first, v[vdx].second));
				v.erase(v.begin() + vdx);
				vdx = 0;
			}
			else 
				vdx++;
		}


		list <pair<int, int>>:: iterator iter;

		for (iter = li.begin(); iter != li.end(); iter++) {
			printf("%d %d ", iter->first, iter->second);
		}

		li.clear();

	}

}