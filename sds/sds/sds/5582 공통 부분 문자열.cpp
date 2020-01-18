#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>

char a[4001], b[4001];
int dp[4001][4001];

int main() {
	scanf("%s%s", a, b);

	int max = 0;
	for (int i = 0; i < strlen(a); i++) {
		for (int j = 0; j < strlen(b); j++) {
			if (a[i] == b[j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
				if (max < dp[i + 1][j + 1]) {
					max = dp[i + 1][j + 1];
				}
			}
		}
	}

	printf("%d", max);

	return 0;
}


/*
D[i][j] i번째 보고 j번째 봤을 때 공통
if(a[i]==b[j])
	D[i-1][j-1]+1

*/