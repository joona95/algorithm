#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

using namespace std;

int dp[1001];

int gcd(int x, int y) {
	if (y == 0) {
		return x;
	}
	else {
		return gcd(y, x%y);
	}
}

int main() {
	int c;
	scanf("%d", &c);

	dp[0] = 0;
	dp[1] = 3;
	for (int i = 2; i <= 1000; i++) {
		dp[i] = dp[i - 1];
		for (int j = 1; j <= i; j++) {
			if (gcd(i, j) == 1) {
				dp[i]+=2;
			}
		}
	}

	for (int i = 0; i < c; i++) {
		int n;
		scanf("%d", &n);

		printf("%d\n", dp[n]);
	}
	
	return 0;
}


/*
시간초과
for (int i = 0; i < c; i++) {
		int n;
		scanf("%d", &n);

		int answer = 1 + (n + 1);
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (gcd(i, j) == 1) {
					answer++;
				}
			}
		}

		printf("%d\n", answer);
	}
*/