#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

int arr[1000005];
int dp[1000005];
int par[1000005];
int ans[1000005];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}

	int cnt = 0;
	int idx = 0;
	for (int i = 1; i <= n; i++) {
		int max = 0;
		for (int j = 1; j <= i-1; j++) {
			if (arr[i] > arr[j]) {
				if (max < dp[j]) {
					max = dp[j];
					par[i] = j;
				}
			}
		}
		dp[i] = max + 1;

		if (dp[i] > cnt) {
			cnt = dp[i];
			idx = i;
		}
	}

	printf("%d\n", cnt);

	int total = 0;
	while (idx!=0) {
		ans[total++] = arr[idx];
		idx = par[idx];
	}

	for (int i = total - 1; i >= 0; i--) {
		printf("%d ", ans[i]);
	}


	return 0;
}
/*
10 20 10 30 20 50
1  2  1  3  2  4

시간초과
1000000 -> n^2 불가한데 어케하지?
n안에 풀어야함

10 20 10 50 20 30 40
1  2  1  3  2  3  4



*/