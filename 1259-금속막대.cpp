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

			// ù ��°�� ���
			if (li.empty()) {
				li.push_back(make_pair(x, y));
				continue;
			}

			// ����Ʈ �� ���� ������� �ݼӸ����� �ϳ��� ũ�Ⱑ ���ٸ�
			if (li.front().first == y) {
				li.push_front(make_pair(x, y));
			}
			// ����Ʈ �� �������� �ϳ���� �ݼӸ����� ������ ũ�Ⱑ ���ٸ�
			else if (li.back().second == x) {
				li.push_back(make_pair(x, y));
			}
			else {
				v.push_back(make_pair(x, y));
			}
		}

		vector <pair<int, int>>::iterator v_iter;
		v_iter = v.begin();

		// ���Ͱ� �� ������ ����
		while (!v.empty()) {

			// �� �ڿ� ���� ���� ��
			if (v[vdx].first == li.back().second) {
				li.push_back(make_pair(v[vdx].first, v[vdx].second));
				v.erase(v.begin()+vdx);
				vdx = 0;
			}
			// �� �տ� ���� ���� ��
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