//2020.01.15
//11660

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

int arr[1030][1030];
int dp[1030][1030];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dp[i + 1][j + 1] = dp[i + 1][j] + dp[i][j + 1] - dp[i][j] + arr[i+1][j+1];
		}
	}

	/*
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}
	*/

	
	for (int i = 1; i <= m; i++) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

		int result = dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1];
		printf("%d\n", result);
	}

	return 0;
}

/*
0 0 0 0 0
0 1 2 3 4
0 2 3 4 5
0 3 4 5 6
0 4 5 6 7

0 0  0  0  0
0 1  3  6  10
0 3  8  15 24
0 6  15 27 42
0 10 24 42 64

(3,3)

(2,2) (3,4)
(3,4) (3,4)
(1,1) (4,4)

*/