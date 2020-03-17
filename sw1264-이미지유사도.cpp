#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
int arr[501][501]; // 0으로 초기화 됨

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

		//첫행과 첫열은 0인 상태.
		
		for (int j = 0; j < str2Len; j++) {

			for (int i = 0; i < str1Len; i++) {
				// 문자열이 다를 경우
				if (str1[i] != str2[j]) {

					// 현재 위치(arr[j+1][i+1])에서 위쪽값이 왼쪽값보다 크면
					if (arr[j][i+1] >= arr[j+1][i])
						arr[j + 1][i + 1] = arr[j][i + 1];

					// 현재 위치(arr[j+1][i+1])에서 왼쪽값이 위쪽값보다 크면
					else if (arr[j][i + 1] <= arr[j + 1][i])
						arr[j + 1][i + 1] = arr[j + 1][i];
				}

				// 문자열이 같을 경우, 현재 위치의 대각선 값 + 1
				else {
					arr[j + 1][i + 1] = arr[j][i] + 1;
				}
			}

		}

		result = double(arr[str2Len][str1Len]);
		
		printf("#%d %.2f\n", t, result / N * 100);

		// arr 초기화
		for (int i = 0; i < N + 1; i++) {
			for (int j = 0; j < N + 1; j++){
				arr[i][j] = 0;
			}
		}


	}


}