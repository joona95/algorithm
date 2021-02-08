#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

using namespace std;

int dp[21][10001];

int main() {
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		int N;
		scanf("%d", &N);
		int coin[21];
		for (int j = 1; j <= N; j++) {
			scanf("%d", &coin[j]);
		}
		int M;
		scanf("%d", &M);


		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= M; k++) {
				dp[j][k] = 0;
			}
		}

		//for (int k = 1; k <= M / coin[1]; k++) {
		//	dp[1][coin[1] * k] = 1;
		//}

		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= M;k++) {
				int q = k / coin[j];
				int r = k % coin[j];

				if(r==0)
					dp[j][k] = 1;

				for (int l = q; l >= 0; l--) {
					dp[j][k] += dp[j - 1][k - l * coin[j]];
				}
			}

			/*
			printf("**%d**\n", j);
			for (int k = 1; k <= M; k++) {
				printf("%d: %d\n", k, dp[j][k]);
			}*/
		}

		printf("%d\n", dp[N][M]);
	}

	return 0;
}