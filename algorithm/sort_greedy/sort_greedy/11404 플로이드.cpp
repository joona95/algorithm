#include <iostream>
using namespace std;

int dp[105][105];
int main() {
	int n, m, a, b, c;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (dp[a][b] ==0 || dp[a][b] > c) {
			dp[a][b] = c;
		}
	}


	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if ((i!=j&&dp[i][k]!=0&&dp[k][j]!=0) && ((dp[i][j]==0 &&dp[i][k]+dp[k][j]!=0) || dp[i][j] > (dp[i][k] + dp[k][j]))) {
					dp[i][j] = dp[i][k] + dp[k][j];
				}
			}
		}

		
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}


	return 0;
}