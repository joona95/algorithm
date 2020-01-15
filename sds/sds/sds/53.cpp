//2020.01.15
//1932

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

int tri[505][505];
int dp[505][505];

int max(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			scanf("%d", &tri[i][j]);
		}
	}

	dp[1][1] = tri[1][1];
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = tri[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);
		}
	}

	int max = 0;
	for (int i = 1; i <= n; i++) {
		if (max < dp[n][i]) {
			max = dp[n][i];
		}
	}
	printf("%d", max);

	return 0;
}

/*
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5


*/