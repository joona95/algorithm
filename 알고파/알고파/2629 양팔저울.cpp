#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cmath>

using namespace std;

int w[31];
bool dp[31][40001];

int main() {
	int n, k;
	scanf("%d", &n);

	int sum = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
		sum += w[i];
	}
	
	dp[0][0] = true;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {
			if (dp[i-1][j]==true) {
				dp[i][j] = true;
				dp[i][j + w[i]] = true;
				dp[i][abs(j - w[i])] = true;
			}
			dp[i][w[i]] = true;
		}

		/*
		for (int j = 0; j <= sum; j++) {
			if (dp[i][j] == false) {
				printf("X ");
			}
			else {
				printf("O ");
			}
		}
		printf("\n");*/
	}

	scanf("%d", &k);

	for (int i = 1; i <= k; i++) {
		int b;
		scanf("%d", &b);

		if (dp[n][b] == false) {
			printf("N ");
		}
		else {
			printf("Y ");
		}
	}

	return 0;
}
