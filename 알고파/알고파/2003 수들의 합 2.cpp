#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

using namespace std;

int dp[10001];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		int k;
		scanf("%d", &k);

		dp[i] = dp[i - 1] + k;
	}

	int s=0, e=1;
	int answer = 0;
	while (s<=e && e <= n) {
		//printf("s:%d e:%d dp[e]-dp[s]:%d\n", s, e, dp[e] - dp[s]);
		if (dp[e] - dp[s] <= m) {
			if (dp[e] - dp[s] == m) {
				answer++;
			}
			e++;
		}
		else {
			s++;
		}
	}

	printf("%d", answer);

	return 0;
}

/*
while 조건문에 s<e가 아니고 s<=e

반례)
5 2
5 2 10000 1 1
*/