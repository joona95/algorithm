#include <iostream>
using namespace std;

int dp[105][105];
int main() {
	int n, m, a, b;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		dp[a][b] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if ((i != j && dp[i][k] != 0 && dp[k][j] != 0) && (dp[i][j] < dp[i][k] + dp[k][j])) {
					dp[i][j] = 1;
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dp[i][j] != 0) {
				dp[j][i] = 1;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		int total = 0;
		for (int j = 1; j <= n; j++) {
			if (dp[i][j] != 0) {
				total++;
			}
		}
		cout << (n - 1) - total<<"\n";
	}

	return 0;
}