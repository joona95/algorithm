#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#define INF 1e9

using namespace std;

int dist[51][51];

int main() {
	int n;
	scanf("%d\n", &n);

	//√ ±‚»≠!!
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				dist[i][j] = 0;
			}
			else {
				dist[i][j] = INF;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		char c;
		for (int j = 1; j <= n; j++) {
			scanf("%c", &c);
			if (c == 'Y') {
				dist[i][j] = 1;
			}
		}
		scanf("%c", &c);
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	int max = 0;
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (dist[i][j]!=0&&dist[i][j] <= 2) {
				cnt++;
			}
			//printf("%d ", dist[i][j]);
		}
		//printf("\n");

		if (max < cnt) {
			max = cnt;
		}
	}

	printf("%d", max);

	return 0;
}