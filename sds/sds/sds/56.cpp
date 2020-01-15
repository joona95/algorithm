//2020.01.15
//2579

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

int arr[305];
int dp[305];

int max(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}

	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];

	for (int i = 3; i <= n; i++) {
		dp[i] = max(arr[i] + arr[i - 1] + dp[i - 3], arr[i] + dp[i - 2]);
	}

	printf("%d", dp[n]);

	return 0;
}


/*
0 10 20 15 25 10 20
  
0 10 30 


*/