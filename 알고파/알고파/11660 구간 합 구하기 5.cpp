#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

using namespace std;

int dp[1025][1025];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int k;
			scanf("%d", &k);
			dp[i][j] = k + dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];
		}
	}
	/*
	printf("***\n");
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}
	printf("***\n");*/

	for (int i = 1; i <= m; i++) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		int answer = dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1];
		printf("%d\n", answer);
	}

	return 0;
}