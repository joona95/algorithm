#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

char a[1001], b[1001];
int dp[1001][1001];
char ans[1001];

int max(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}

/*
void dfs(int r, int c) {
	if (!dp[r][c])
		return;

	if (a[r - 1] == b[c - 1]) {
		ans.push(a[r - 1]);
		dfs(r - 1, c - 1);
	}
	else {
		if (dp[r - 1][c] == dp[r][c]) {
			dfs(r - 1, c);
		}
		else if (dp[r][c - 1] == dp[r][c]) {
			dfs(r, c - 1);
		}
	}
}
*/

int main() {
	scanf("%s%s", a, b);

	//int cnt = 0, r, c;
	for (int i = 0; i < strlen(a); i++) {
		for (int j = 0; j < strlen(b); j++) {
			
			if (a[i] == b[j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
			}
			else {
				int maxv =  max(dp[i][j + 1], dp[i + 1][j]);
				dp[i + 1][j + 1] = maxv;
			}

			/*
			if (dp[i + 1][j + 1] > cnt) {
				cnt = dp[i + 1][j + 1];
				r = i + 1;
				c = j + 1;
			}*/
		}
	}

	//printf("%d %d\n", idx_r, idx_c);

	//dfs(idx_r, idx_c);
	int cnt = 0;
	int r = strlen(a);
	int c = strlen(b);
	while (dp[r][c]) {
		if (dp[r][c] == dp[r][c - 1]) {
			c--;
		}
		else if (dp[r][c] == dp[r - 1][c]) {
			r--;
		}
		else if (dp[r][c] - 1 == dp[r - 1][c - 1]) {
			ans[cnt++] = a[r - 1];
			r--;
			c--;
		}
	}

	printf("%d\n", cnt);
	for (int i = cnt - 1; i >= 0; i--) {
		printf("%c", ans[i]);
	}
	/*
	while (!ans.empty()) {
		printf("%c", ans.top());
		ans.pop();
	}
	*/
	//printf("\n");

	/*
	for (int i = 1; i <= strlen(a); i++) {
		for (int j = 1; j <= strlen(b); j++) {
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}
	*/

	return 0;
}