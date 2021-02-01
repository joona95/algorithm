#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

long long dp[70];

long long koong(int n) {
	if (n < 2) {
		dp[n] = 1;
		return 1;
	}
	if (n == 2) {
		dp[n] = 2;
		return 2;
	}
	if (n == 3) {
		dp[n] = 4;
		return 4;
	}

	
	dp[n] = koong(n - 1) + dp[n - 2] + dp[n - 3] + dp[n - 4];

	return dp[n];
}

int main() {
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		int n;
		scanf("%d", &n);

		long long answer = koong(n);

		printf("%lld\n", answer);
	}

	return 0;
}