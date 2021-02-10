#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

using namespace std;

int dp[21][21][21];

int w(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) {
		return 1;
	}
	else if (a > 20 || b > 20 || c > 20) {
		return w(20, 20, 20);
	}
	else if (a < b && b < c) {
		if (dp[a][b][c] != 0)
			return dp[a][b][c];

		return dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	}
	else {
		if (dp[a][b][c] != 0)
			return dp[a][b][c];

		return dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	}
}

int main() {

	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	while (a != -1 || b != -1 || c != -1) {
		for (int i = 0; i <= 20; i++) {
			for (int j = 0; j <= 20; j++) {
				for (int k = 0; k <= 20; k++) {
					dp[i][j][k] = 0;
				}
			}
		}

		int answer = w(a, b, c);
		printf("w(%d, %d, %d) = %d\n", a, b, c, answer);

		scanf("%d %d %d", &a, &b, &c);
	}

	return 0;
}

/*
a,b,c 다 하는 삼차원 배열에 dp

배열 초기화 idx는 0~20으로
*/