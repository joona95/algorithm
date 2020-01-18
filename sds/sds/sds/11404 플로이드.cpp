#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>

using namespace std;

int cost[105][105];

int min(int a, int b) {
	if (a > b)
		return b;
	else
		return a;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);

		if (cost[a][b] == 0)
			cost[a][b] = c;
		else
			cost[a][b]=min(cost[a][b], c);
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (cost[i][k]>0&&cost[k][j] > 0&&i!=j) {
					if (cost[i][j] == 0 || cost[i][j] > cost[i][k] + cost[k][j])
						cost[i][j] = cost[i][k] + cost[k][j];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", cost[i][j]);
		}
		printf("\n");
	}

	return 0;
}
/*

*/