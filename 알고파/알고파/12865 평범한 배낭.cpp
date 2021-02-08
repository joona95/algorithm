#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

using namespace std;

int W[101];
int V[101];

int dp[101][100001];

int main() {
	int N, K;
	scanf("%d %d", &N, &K);

	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &W[i], &V[i]);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (j < W[i]) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				if (dp[i - 1][j] >= dp[i - 1][j - W[i]] + V[i]) {
					dp[i][j] = dp[i - 1][j];
				}
				else {
					dp[i][j] = dp[i - 1][j - W[i]] + V[i];
				}
			}
		}
	}

	printf("%d", dp[N][K]);

	return 0;
}