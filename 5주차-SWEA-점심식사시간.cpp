#define _CRT_SECURE_NO_WARNINGS
#define NumOfMagnet 4
#define NumOfBlades 8

#define M_INF -100
#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int arr[10][10]; // ���� ��ǲ���� �޴� �迭
int assignment[10][10]; // ����� �����ϴ� �迭
int simul[10][10]; // �ùķ��̼��� �����ϴ� �迭
int stair[10];
int time;
int MinTime = 1000001;
int peopleCnt;
bool allMINF;

vector<pair<int, int>> stairIdx;
vector<int> stairOne;
vector<int> stairTwo;

bool compare(int a, int b) {
	return a > b;
}

void dfs(int cnt) {

	// ���� ���. �� ���̽��� ���Ͽ� �ùķ��̼� ����
	if (cnt == peopleCnt) {
		int idx = 0;
		time = 0; // ���� ����
		// simul �� ������� ��� ���� �� �Ÿ��� ǥ���ϱ�
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j] == 1) 
					assignment[i][j] = stair[idx++];

				if (assignment[i][j] == 1) // 1�� ����� ����� �Ÿ� ���				
					simul[i][j] = abs(i - stairIdx[0].first) + abs(j - stairIdx[0].second);
				
				else if (assignment[i][j] == 2) // 2�� ����� ����� �Ÿ� ���				
					simul[i][j] = abs(i - stairIdx[1].first) + abs(j - stairIdx[1].second);
				
			}
		}

		// 1�о� �ð��� �帥��. ��� �Ա��� ���� ��, 1�� �ں��� ����� ������ �� �ִ�.
		time = 1; // ����
		while (1) {

			// 1���� �ð��� �带 �� ������ �Ÿ��� �ϰ������� -1 �����ϴ� �۾�.
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (simul[i][j] != M_INF && simul[i][j] != -1) {
						// �̹� -1�� ������� �������⸦ ����ؾ� �ϹǷ� ���ҽ�Ű�� �ʴ´�.
						simul[i][j] -= 1;
					}
				}
			}

			// ��� �������� ���Ͱ� ��� ���� ���� ���, ������ ���ҵ��� �ϰ������� 1 ���ҽ�Ű�� �۾�
			// 0�� �Ǹ� �� ���Ϳ��� �����. ���� �����ϵ��� �������� �����Ͽ� 0�� �� ���� ������ �����Ѵ�.
			sort(stairOne.begin(), stairOne.end(), compare);
			sort(stairTwo.begin(), stairTwo.end(), compare);

			if (stairOne.size() != 0) {
				for (int i = stairOne.size() -1 ; i >= 0; i--) {
					stairOne[i] -= 1;
					if (stairOne[i] == 0) {
						stairOne.erase(stairOne.begin() + i);
					}
				}				
			}
			if (stairTwo.size() != 0) {
				for (int i = stairTwo.size() - 1; i >= 0; i--) {
					stairTwo[i] -= 1;
					if (stairTwo[i] == 0) {
						stairTwo.erase(stairTwo.begin() + i);
					}
				}
			}


			// -1�� �� ������� ����� �������� ���� ���Ϳ� �ִ� �۾�.
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (simul[i][j] == -1 && assignment[i][j] == 1
						&& stairOne.size() < 3) { // queue�� �־� �д�.
						stairOne.push_back(arr[stairIdx[0].first][stairIdx[0].second]);
						simul[i][j] = M_INF; // �̹� �� ���̹Ƿ� ���ֹ�����.
					}
					else if (simul[i][j] == -1 && assignment[i][j] == 2
						&& stairTwo.size() < 3) { // queue�� �־� �д�.
						stairTwo.push_back(arr[stairIdx[1].first][stairIdx[1].second]);
						simul[i][j] = M_INF; // �̹� �� ���̹Ƿ� ���ֹ�����.
					}
				}
			}

			// ��� simul ���� ���Ͱ� M_INF�� �Ǿ����� stairOne, Two ���Ϳ��� �� �̻� �������� ����� ���� ���
			// while���� �����Ѵ�.
			allMINF = true;
			for (int i = 0; i < N; i++){
				for (int j = 0; j < N; j++) {
					if (simul[i][j] != M_INF) {
						allMINF = false;
					}
				}
			}
			if (allMINF && stairOne.empty() && stairTwo.empty())
				break;		
			
			// �ƴϸ� �ð��� 1�� �����Ѵ�.
			time += 1;
		}	

		return;
	}

	// stair Num���θ� ǥ��
	for (int i = 1; i <= 2; i++) {
		stair[cnt] = i;
		dfs(cnt + 1);

		if (MinTime > time)		
			MinTime = time;
		
		stair[cnt] = 0;
	}

}

int main() {

	int T;
	FILE* fp = fopen("input.txt", "r");

	fscanf(fp, "%d", &T);

	for (int t = 1; t <= t; t++) {
		fscanf(fp, "%d", &N);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				fscanf(fp, "%d", &arr[i][j]);
				if (arr[i][j] == 1) {
					peopleCnt += 1;
				}
				if (arr[i][j] != 0 && arr[i][j] != 1) {
					stairIdx.push_back({ i,j });
				}
				simul[i][j] = M_INF;
				assignment[i][j] = 0;
			}
		}


		dfs(0);

		printf("#%d %d\n",t, MinTime);

		MinTime = 1000001;
		peopleCnt = 0;
		stairIdx.clear();
		time = 0;
		stairOne.clear();
		stairTwo.clear();
	}
}