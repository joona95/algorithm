#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

int arr[100005];
int dp[100005][5][5];

int min(int a, int b) {
	return (a > b ? b : a);
}

int calc(int pre, int next) {
	if (pre == next) {
		return 1;
	}
	else if (pre == 0) {
		return 2;
	}
	else if (pre + 2 == next || pre - 2 == next) {
		return 4;
	}
	else {
		return 3;
	}
}

int main() {

	
	int n = 1;
	while (1) {
		int cmd;
		scanf("%d", &cmd);

		if (cmd == 0)
			break;

		arr[n++] = cmd;
	}

	for (int i = 0; i <= n; i++) {
		for (int l = 0; l <= 4; l++) {
			for (int r = 0; r <= 4; r++) {
				dp[i][l][r] = 1e9;
			}
		}
	}

	dp[0][0][0] = 0;
	dp[1][0][arr[1]] = 2;
	dp[1][arr[1]][0] = 2;
	for (int i = 1; i < n; i++) {
		for (int l = 0; l <= 4; l++) {
			for (int r = 0; r <= 4; r++) {
				if (l == r)
					continue;

				if (l == arr[i]) {
					for (int j = 0; j <= 4; j++) {
						dp[i][l][r] = min(dp[i][l][r], dp[i - 1][j][r] + calc(j,arr[i])); //l이 움직였을때
					}
				}
				else if (r == arr[i]) {
					for (int j = 0; j <= 4; j++) {
						dp[i][l][r] = min(dp[i][l][r], dp[i - 1][l][j] + calc(j,arr[i])); //r이 움직였을때
					}
				}
			}
		}
	}

	
	for (int i = 0; i < n; i++) {
		for (int l = 0; l <= 4; l++) {
			for (int r = 0; r <= 4; r++) {
				printf("%d ", dp[i][l][r]);
			}
			printf("\n");
		}
		printf("\n****\n");
	}
	
	
	int result = 1e9;
	for (int j = 0; j <= 4; j++) {
		result = min(result, dp[n - 1][j][arr[n - 1]]);
	}
	for (int j = 0; j <= 4; j++) {
		result = min(result, dp[n - 1][arr[n - 1]][j]);
	}

	printf("%d", result);
	

	return 0;
}

/*
d[i,l,r] 앞으로 모든 step 필요한 최소 비용

d[100001][5][5]
i번째일때 left가 어디에 있고, right가 어디에 있을때 필요한 최소 비용

두발이 같은 지점x
중앙->다른지점:2
다른지점에서 인접(왼쪽에서 위/아래)한 지점으로 이동:3
반대편(위->아래/오른->왼):4
같은지점:1

1 2 2 4 : 8
(0, 0) -> (0, 1) -> (2, 1) -> (2, 1) -> (2, 4)
              2      2         1            3
		  (1, 0)    (0, 2)




*/