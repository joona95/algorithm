#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
int arr[305][305];
int dp[305][305];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &arr[i][j]);
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i-1][j-1] + arr[i][j];
		}
	}

	int k;
	scanf("%d", &k);
	for (int l = 0; l < k; l++) {
		int i, j, x, y;
		scanf("%d%d%d%d", &i, &j, &x, &y);

		printf("%d\n", dp[x][y] - dp[x][j - 1]-dp[i-1][y]+dp[i-1][j-1]);

		/*
		//맞지만 DP로 풀었다고 보기힘들다
		int sum = 0;
		for (int a = i; a <= x; a++) {
			for (int b = j; b <= y; b++) {
				sum += dp[a][b];
			}
		}

		printf("%d\n", sum);
		*/
	}

	return 0;
}