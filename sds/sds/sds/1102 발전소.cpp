#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>

int n, p;
int arr[20][20];
char light[20];
int dp[1 << 16];

int min(int a, int b) {
	return (a > b ? b : a);
}

int sol(int cnt, int state) {

	if (cnt == p) {
		return 0;
	}

	if (dp[state] != 1e9)
		return dp[state];

	for (int i = 0; i < n; i++) {
		if ((state&(1<<i))!=0) {
			for (int j = 0; j < n; j++) {
				if (i != j && (state&(1 << j)) == 0) {
					dp[state] = min(dp[state], sol(cnt + 1, (state | 1 << j)) + arr[i][j]);
	
				}
			}
		}
	}

	return dp[state];
}


int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}



	scanf("%s", light);
	scanf("%d", &p);

	int cnt=0, state=0;
	for (int i = strlen(light) - 1; i >= 0; i--) {
		if (light[i] == 'Y') {
			state = state << 1;
			state += 1;
			cnt++;
		}
		else {
			state = state << 1;
		}
	}


	for (int i = 0; i < (1<<n); i++) {
		dp[i] = 1e9;
	}


	if (cnt == 0) { //켜져있는 갯수가 0일때
		if (p == 0)
			printf("0");
		else
			printf("-1");
	}
	else if (cnt > p) { //켜져 있는 갯수가 켜야하는 갯수보다 많을때 더 켜지 않아도 됨
		printf("0");
	}
	else {
		printf("%d", sol(cnt, state));
	}


	return 0;
}
/*
풀려야 재밌는데 안풀리니까 재미없어요 .......


*/
