#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

int n;
int w[20][20];
int dp[20][1<<16];

int min(int a, int b) {
	return (a > b ? b : a);
}

int tsp(int cur, int state) {

	if (state == (1 << n) - 1) {
		if (!w[cur][0])
			return 1e9;
		else
			return w[cur][0];
	}//다시 원래의 도시로 돌아올수있는지 확인

	if (dp[cur][state] != 1e9)
		return dp[cur][state]; //안하면 시간초과

	for (int i = 0; i < n; i++) {//다음 방문할 도시 전부 시도
		if ((state&(1<<i))==0&&w[cur][i]!=0) {//해당 도시를 방문하지 않았고못가는경우가 아니면
			dp[cur][state] = min(dp[cur][state], tsp(i, (state|1 << i)) + w[cur][i]);
		}
	}

	return dp[cur][state];
}


int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &w[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (1 << n); j++) {
			dp[i][j] = 1e9;
		}
	}

	printf("%d", tsp(0,1));

	return 0;
}


/*
n=16
d[16 , 2^16]
비트연산..?

d[0, 0000..1] 앞으로 필요한 금액

배열
초기값
d(cur,111..1)=A(cur,0)
점화식
d(current, state)+A[cur,0] ..?


비트연산문제 : 타일링 문제 11726

*/

