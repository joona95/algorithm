#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

int mem[105];
int cost[105];
int dp[105][10005];

int max(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &mem[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &cost[i]);
	}


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 10000; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j - cost[i] >= 0) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j-cost[i]] + mem[i]);
			}
		}
	}
	/*
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 20; j++) {
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}
	*/
	
	
	int min = 10001;
	int result;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 10000; j++) {
			if (m <= dp[i][j]) {
				if(min>j)
					min = j;
			}
		}
	}

	printf("%d", min);
	
	return 0;
}

/*
D[i][j] : i번째 앱까지 최소 j만큼 메모리를 확보하는데 필요한 비용
D[1][30]=3

D[i][c]: i번째 앱까지 c만큼 비용으로 확보가능한 메모리

5 60
30 10 20 35 40
3  0  3  5  4

(1,0):0
(1,3):30
(2,0):10
(2,3):40
(3,0):10
(3,3):30
(3,6):60



*/