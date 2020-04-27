#define _CRT_SECURE_NO_WARNINGS
#define NumOfMagnet 4
#define NumOfBlades 8
#include <iostream>
#include <vector>

using namespace std;

bool SameOrDiff[3];
int DoCycle[4];

void Clockwise(vector<int> &magnet) {	
	vector<int>::iterator iter;
	int temp;

	iter = magnet.begin();
	temp = magnet[magnet.size() - 1];
	magnet.pop_back();
	magnet.insert(iter, temp);
}

void ctr_Clockwise(vector<int> &magnet) {
	vector<int>::iterator iter;
	int temp;

	iter = magnet.begin();
	temp = *iter;
	magnet.erase(magnet.begin());
	magnet.push_back(temp);
}

int main() {

	int T, K, input, mNum, dir;
	int score = 0, twice = 1;
	vector<vector<int>> magnet;
	vector<pair<int, int>> cycle;
	
	scanf("%d", &T);
	
	for (int t = 1; t <= T; t++) {

		scanf("%d", &K);

		for (int i = 0; i < NumOfMagnet; i++) {
			vector<int> temp;
			for (int j = 0; j < NumOfBlades; j++) {
				scanf("%d", &input);
				temp.push_back(input);
			}
			magnet.push_back(temp);
		}

		for (int i = 0; i < K; i++) {
			scanf("%d %d", &mNum, &dir);
			cycle.push_back({ mNum, dir });
		}

		// margnet �ε��� ��ȣ in 0�� N��, 1�� S�� // �ð������ 1, �ݽð������ -1
		// �ڼ����� ������ �ƴ��� SameOrDiff�� ó�� ǥ��		
		for (int i = 0; i < NumOfMagnet - 1; i++) {
			if (magnet[i][2] == magnet[i + 1][6]) 
				SameOrDiff[i] = true;		
			else
				SameOrDiff[i] = false;
		}

		// �׽�Ʈ ����
		for (int i = 0; i < K; i++) {
			mNum = cycle[i].first; dir = cycle[i].second;
			DoCycle[mNum - 1] = dir;

			// mNum�� �ڼ��� dir �������� ȸ����Ų��. mNum�� �ڼ� ȸ����, �ٸ� �ڼ��� ���� �ľ�		
			if (mNum - 1 == 0) { // 0�� �ڼ�
				if (SameOrDiff[0] == false) 
					DoCycle[1] = DoCycle[mNum - 1] * -1;				
				if (SameOrDiff[1] == false) 
					DoCycle[2] = DoCycle[1] * -1;				
				if (SameOrDiff[2] == false) 
					DoCycle[3] = DoCycle[2] * -1;			
			}
			else if (mNum - 1 == 1) { // 1�� �ڼ� - 0���� 2���� ����
				if (SameOrDiff[0] == false) 
					DoCycle[0] = DoCycle[mNum - 1] * -1;
				if (SameOrDiff[1] == false) 
					DoCycle[2] = DoCycle[mNum - 1] * -1;
				if (SameOrDiff[2] == false) 
					DoCycle[3] = DoCycle[2] * -1;
			}
			else if (mNum - 1 == 2) {
				if (SameOrDiff[1] == false) 
					DoCycle[1] = DoCycle[mNum - 1] * -1;
				if (SameOrDiff[2] == false) 
					DoCycle[3] = DoCycle[mNum - 1] * -1;
				if (SameOrDiff[0] == false) 
					DoCycle[0] = DoCycle[1] * -1;
			}
			else if (mNum - 1 == 3) {
				if (SameOrDiff[2] == false) 
					DoCycle[2] = DoCycle[mNum - 1] * -1;
				if (SameOrDiff[1] == false) 
					DoCycle[1] = DoCycle[2] * -1;
				if (SameOrDiff[0] == false) 
					DoCycle[0] = DoCycle[1] * -1;
			}

			for (int i = 0; i < NumOfMagnet; i++) {
				if (DoCycle[i] == 1)  /* �ð� ���� ȸ�� */
					Clockwise(magnet[i]);
				else if (DoCycle[i] == -1)  /* �ݽð� ���� ȸ�� */
					ctr_Clockwise(magnet[i]);
			}
			//DoCycle �ٽ� 0���� �ʱ�ȭ
			for (int i = 0; i < NumOfMagnet; i++)
				DoCycle[i] = 0;

			// ȸ���� ���� ���� �� ���θ� �ٽ� ǥ��
			for (int i = 0; i < NumOfMagnet - 1; i++) {
				if (magnet[i][2] == magnet[i + 1][6]) 
					SameOrDiff[i] = true;			
				else
					SameOrDiff[i] = false;
			}
		}

		// ���� ����ϱ�
		twice = 1; score = 0;

		for (int i = 1; i <= NumOfMagnet; i++) {
			if (magnet[i - 1][0] == 0)
				score += 0;
			else if (magnet[i - 1][0] == 1)
				score += twice;
			twice*=2;
		}

		printf("#%d %d",t, score);

		// ����
		magnet.clear();
		cycle.clear();
	}
}