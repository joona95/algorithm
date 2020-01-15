//2020.01.15
//1915

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

int arr[1005][1005];
int dp[1005][1005];

int min(int a, int b) {
	if (a > b)
		return b;
	else
		return a;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			scanf("%1d", &arr[i][j]);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if(arr[i][j])
				dp[i][j] = min(dp[i-1][j-1], min(dp[i - 1][j], dp[i][j - 1])) + arr[i][j];
		}
	}

	int max = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (max < dp[i][j]) {
				max = dp[i][j];
			}
		}
	}

	int result = max*max;
	printf("%d", result);

	return 0;
}

/*
4 4
00000
00100
00111
01120
00010

4 4
000001
001000
001110
011221
001231

*/