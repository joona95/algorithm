#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

using namespace std;

int num[100001];
int dp[100001];

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &num[i]);
	}

	dp[1] = num[1];
	for (int i = 2; i <= n; i++) {
		if (dp[i - 1] + num[i] > num[i]) {
			dp[i] = dp[i - 1] + num[i];
		}
		else {
			dp[i]= num[i];
		}
	}

	int max = -100000001;
	for (int i = 1; i <= n; i++) {
		if (max < dp[i]) {
			max = dp[i];
		}
	}

	printf("%d", max);

	return 0;
}