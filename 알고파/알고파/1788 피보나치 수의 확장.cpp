#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

using namespace std;

long long dp[1000001];

int function(int n) {
	if (n == 0) {
		dp[n] = 0;
		return dp[n];
	}
	if (n == 1) {
		dp[n] = 1;
		return dp[n];
	}

	dp[n] = (function(n - 1) + dp[n - 2])%1000000000;

	return dp[n];
}


int main() {
	int n;
	scanf("%d", &n);

	int answer;
	if (n < 0) {
		answer = function(-n);
	}
	else {
		answer = function(n);
	}

	if (n > 0) {
		printf("1\n%d", answer);
	}
	else if (n == 0) {
		printf("0\n%d",answer);
	}
	else {
		if (n % 2 == 0) {
			printf("-1\n%d", answer);
		}
		else {
			printf("1\n%d", answer);
		}
	}

	return 0;
}

/*
절댓값은 똑같은데 n<0 이면 짝수는 음수, 홀수는 양수.
*/