#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>

using namespace std;

int num[10001];
int dp[10001];

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &num[i]);
	}

	sort(num + 1, num + n + 1);

	dp[0] = 0;
	dp[1] = num[1];
	for (int i = 2; i <= n; i++) {
		if (dp[i - 2] + (num[i - 1] * num[i]) > dp[i - 1] + num[i]) {
			dp[i] = dp[i - 2] + (num[i - 1] * num[i]);
		}
		else {
			dp[i] = dp[i - 1] + num[i];
		}
	}

	printf("%d", dp[n]);

	return 0;
}