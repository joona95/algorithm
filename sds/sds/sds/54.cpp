//2020.01.15
//11659

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

int arr[100005];
int dp[100005];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1] + arr[i];
	}

	for (int i = 1; i <= m; i++) {
		int s, e;
		scanf("%d%d", &s, &e);

		int result = dp[e] - dp[s - 1];
		printf("%d\n", result);
	}

	return 0;
}