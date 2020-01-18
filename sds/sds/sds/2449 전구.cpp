#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

int arr[205];
int dp[205][205];

int min(int a, int b) {
	if (a > b)
		return b;
	else
		return a;
}

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n&&j + i - 1 <= n; j++) {
			for (int k = j; k < j + i - 1; k++) {
				if (!dp[j][j + i - 1])
					dp[j][j + i - 1] = dp[j][k] + dp[k + 1][j + i - 1] + !(arr[j] == arr[k + 1]);
				else
					dp[j][j + i - 1] = min(dp[j][j + i - 1], dp[j][k] + dp[k + 1][j + i - 1] + !(arr[j] == arr[k + 1]));
			}
		}
	}
	//i; 구간의 크기, j:구간의 시작위치

	printf("%d", dp[1][n]);

	return 0;
}

/*
10 3
1 1 /2/ 3 3 3/ 2 2/ 1 1
=>2

1 1 2 2 2 2 2 2 1 1 
1 1 1 1 1 1 1 1 1 1

d[i][j]갯수
d1n: 1~n까지
d11
for(int i=1;i<=n;i++)
	for(int j=1;j<=n&&j+i-1<=n;j++)
		min(dp[j][j+i-1]=d[j][k]+d[k+1][j+i-1]+...)

1 1 2 3 3 3 2 2 1 1

0 0 1
  0 1 2 
    0 1 
	  0 0 
	    0 0 
		  0 1 
		    0 0
			  0 1
			    0 0
				  0


d[i][j]:i번부터 j번까지 전구색을 같게 하는데 드는 횟수
d[1][n]
d[i][j]=d[i][k]+d[k+1][j]+2개가 같게 만드는데 드는 비용

a[i]==a[k+1]? 0:1

d[1][1]=0
d[i][i]=0

*/