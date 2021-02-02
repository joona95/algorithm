#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

using namespace std;

long long dp[81];

int main() {
	int n;
	scanf("%d", &n);

	dp[1] = 1;
	dp[2] = 1;

	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	long long answer = dp[n] * 4 + dp[n - 1] * 2;

	printf("%lld", answer);

	return 0;
}