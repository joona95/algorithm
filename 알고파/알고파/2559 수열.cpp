#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

using namespace std;

int dp[100001];

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; i++) {
		int t;
		scanf("%d", &t);
		dp[i] = dp[i - 1] + t;
	}

	int s = 0, e = k;
	int max = -10000001;
	while (e <= n) {
		if (max < dp[e] - dp[s]) {
			max = dp[e] - dp[s];
		}
		s++;
		e++;
	}

	printf("%d", max);

	return 0;
}