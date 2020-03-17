#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
int arr[501][501]; // 0���� �ʱ�ȭ ��

int main() {

	int T;
	int N;
	int str1Len, str2Len;
	char str1[501];
	char str2[501];
	double result;
	
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d", &N);
		scanf("%s", &str1);
		scanf("%s", &str2);
		str1Len = strlen(str1);
		str2Len = strlen(str2);

		//ù��� ù���� 0�� ����.
		
		for (int j = 0; j < str2Len; j++) {

			for (int i = 0; i < str1Len; i++) {
				// ���ڿ��� �ٸ� ���
				if (str1[i] != str2[j]) {

					// ���� ��ġ(arr[j+1][i+1])���� ���ʰ��� ���ʰ����� ũ��
					if (arr[j][i+1] >= arr[j+1][i])
						arr[j + 1][i + 1] = arr[j][i + 1];

					// ���� ��ġ(arr[j+1][i+1])���� ���ʰ��� ���ʰ����� ũ��
					else if (arr[j][i + 1] <= arr[j + 1][i])
						arr[j + 1][i + 1] = arr[j + 1][i];
				}

				// ���ڿ��� ���� ���, ���� ��ġ�� �밢�� �� + 1
				else {
					arr[j + 1][i + 1] = arr[j][i] + 1;
				}
			}

		}

		result = double(arr[str2Len][str1Len]);
		
		printf("#%d %.2f\n", t, result / N * 100);

		// arr �ʱ�ȭ
		for (int i = 0; i < N + 1; i++) {
			for (int j = 0; j < N + 1; j++){
				arr[i][j] = 0;
			}
		}


	}


}