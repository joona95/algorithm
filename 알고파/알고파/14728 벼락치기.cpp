#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

using namespace std;

int K[101];
int S[101];
int dp[101][10001];

int main() {
	int N, T;
	scanf("%d %d", &N, &T);

	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &K[i], &S[i]);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= T; j++) {
			if (j < K[i]) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				if (dp[i - 1][j] >= dp[i - 1][j - K[i]] + S[i]) {
					dp[i][j] = dp[i - 1][j];
				}
				else {
					dp[i][j] = dp[i - 1][j - K[i]] + S[i];
				}
			}
		}
	}

	printf("%d", dp[N][T]);

	return 0;
}