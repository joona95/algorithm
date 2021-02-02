#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

using namespace std;

int num[1001];
int dp[1001];

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &num[i]);
	}

	for (int i = 1; i <= n; i++) {
		int max = 0;
		for (int j = 1; j < i; j++) {
			if (max < dp[j] && num[j]<num[i]) {
				max = dp[j];
			}
		}
		dp[i] = max + 1;
	}

	int answer = 0;
	for (int i = 1; i <= n; i++) {
		if (answer < dp[i]) {
			answer = dp[i];
		}
	}

	printf("%d", answer);

	return 0;
}