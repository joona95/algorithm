#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

using namespace std;

int dp[1001][10001];
int I[1001];
int T[1001];

int main() {
	int N, K;
	scanf("%d %d", &N, &K);

	for (int i = 1; i <= K; i++) {
		scanf("%d %d", &I[i], &T[i]);
	}

	for (int i = 1; i <= K; i++) {
		for (int j = 1; j <= N; j++) {
			if (j < T[i]) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				if (dp[i - 1][j] >= dp[i - 1][j - T[i]] + I[i]) {
					dp[i][j] = dp[i - 1][j];
				}
				else {
					dp[i][j] = dp[i - 1][j - T[i]] + I[i];
				}
			}
		}
	}

	printf("%d\n", dp[K][N]);

	return 0;
}