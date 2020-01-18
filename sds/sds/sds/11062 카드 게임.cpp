#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

int arr[1005];
int sum[1005];
int dp[1005][1005];

int max(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}

int main() {
	int t;
	scanf("%d", &t);

	for (int l = 1; l <= t; l++) {
		int n;
		scanf("%d", &n);
	
		for (int j = 1; j <= n; j++) {
			scanf("%d", &arr[j]);
			sum[j] = sum[j - 1] + arr[j];
		}


		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n&&j+i-1<=n; j++) {
				if (j == j + i - 1) {
					dp[j][j + i - 1] = arr[j];
				}
				else {
					int s = sum[j + i - 1] - sum[j - 1];
					dp[j][j + i - 1] = max(s - dp[j + 1][j + i - 1], s - dp[j][j + i - 2]);
				}
			}
		}
		
		/*
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				printf("%d ", dp[j][k]);
			}
			printf("\n");
		}*/


		printf("%d\n", dp[1][n]);
	}



	return 0;
}

/*
d[1][n]:근우가 얻게 되는 최고 점수
d[i][j]:i부터 j까지 카드가 있을 때 근우가 얻게 되는 최고 점수

d(i,j) = max(전체점수sum - 상대방이 가질 수 있는 최대점수(d[i+1][j], d[i][j-1]))


1 2 5 2

1 1 1 1 2 2 2 2 2

*/