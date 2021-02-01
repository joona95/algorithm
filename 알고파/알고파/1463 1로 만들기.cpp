#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

using namespace std;

int dp[1000001];

int min(int a, int b) {
	if (a < b) {
		return a;
	}
	else {
		return b;
	}
}

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3] + 1);
		if (i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + 1);
	}

	printf("%d", dp[n]);

	return 0;
}

/*
int function(int n) {
	if (n == 1)
		return 0;

	dp[n] = function(n - 1) + 1;
	if (n % 2 == 0)
		dp[n] = min(dp[n], dp[n/2] + 1);
	if (n % 3 == 0)
		dp[n] = min(dp[n], dp[n / 3] + 1);

	return dp[n];
}

int main() {
	int n;
	scanf("%d", &n);

	int answer = function(n);

	printf("%d", answer);

	return 0;
}
*/