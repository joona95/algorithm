#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

using namespace std;

int L[21];
int J[21];

int dp[21][101];

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &L[i]);
	}
	for (int i = 1; i <= N; i++) {
		scanf("%d", &J[i]);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 100; j++) {
			if (L[i] > j) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				if (dp[i - 1][j] >= dp[i - 1][j - L[i]] + J[i]) {
					dp[i][j] = dp[i - 1][j];
				}
				else {
					dp[i][j] = dp[i - 1][j -L[i]] + J[i];
				}
			}
			
		}
	}

	printf("%d", dp[N][99]);

	return 0;
}
