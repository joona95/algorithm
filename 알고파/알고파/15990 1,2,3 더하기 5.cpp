#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

using namespace std;

int dp[4][100001];

int main() {
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		int n;
		scanf("%d", &n);

		for (int j = 1; j <= 3; j++) {
			for (int k = 0; k <= n; k++) {
				dp[j][k] = 0;
			}
		}

		dp[1][1] = 1;
		dp[2][2] = 1;
		dp[1][3] = 1;
		dp[2][3] = 1;
		dp[3][3] = 1;
		
		for (int j = 4; j <= n; j++) {
			dp[1][j] = (dp[2][j - 1] + dp[3][j - 1])%1000000009;
			dp[2][j] = (dp[1][j - 2] + dp[3][j - 2]) % 1000000009;
			dp[3][j] = (dp[1][j - 3] + dp[2][j - 3]) % 1000000009;
		}

		int answer = ((dp[1][n] + dp[2][n]) % 1000000009 + dp[3][n]) % 1000000009;
		printf("%d\n", answer);
	}

	return 0;
}

/*
중복 제한 없는 경우에는, d[n] = d[n-1]+d[n-2]+d[n-3]

제일 마지막에 오는 숫자가 1,2,3일 때

1000000009로 나눈 나머지 조건 
*/