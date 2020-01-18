#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

bool stu[505][505];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);

		stu[a][b] = true;
	}


	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (stu[i][k] && stu[k][j]) {
					stu[i][j] = true;
				}
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		int count = 0;
		for (int j = 1; j <= n; j++) {
			if (i != j && (stu[i][j] || stu[j][i])) {
				count++;
			}
		}
		if (count == n - 1) {
			cnt++;
		}
	}

	printf("%d", cnt);

	return 0;
}