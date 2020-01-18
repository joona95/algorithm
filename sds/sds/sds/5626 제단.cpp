#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#define MOD 1000000007

int arr[10005];
int dp[2][10005];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}

	if(arr[1]==-1 || arr[1]==0)
		dp[0][0] = 1;
	else
		dp[0][0] = 0;

	for (int i = 2; i <= n; i++) {
		//printf("\n**%d**\n", arr[i]);
		for (int j = 0; j <= n; j++) {
			if (arr[i] == -1) {
				dp[1][j] = dp[0][j];
				if (j - 1 >= 0)
					dp[1][j] = (dp[1][j] + dp[0][j - 1]) % MOD;
				if (j + 1 <= n)
					dp[1][j] = (dp[1][j] + dp[0][j + 1]) % MOD;
			}
			else {
				if (j == arr[i]) {
					dp[1][j] = dp[0][j];
					if (j - 1 >= 0)
						dp[1][j] = (dp[1][j] + dp[0][j - 1]) % MOD;
					if (j + 1 <= n)
						dp[1][j] = (dp[1][j] + dp[0][j + 1]) % MOD;
				}
			}
		}

		for (int j = 0; j <= n; j++) {
			dp[0][j] = dp[1][j];
			dp[1][j] = 0;
			//printf("%d ", dp[0][j]);
		}
		//printf("\n");
	}
	

	printf("%d", dp[0][0]);

	return 0;
}

/*
d[1][0]=1  d[1][0]/d[1][0]+d[1][1]
d[1][1]=0
d[n][0]....=0

점화식
d[i][j]=
i번째에서 j높이를 가지는 케이스수
d[i][j]=d[i-1][j-1] + d[...][j]

??????????????


n=6

j
0  1  1  2  0  0  3<=답 d[n][0]
1  0  1  2  0  3  0
2  0  0  1  3  3  0
3  0  0  0  0  3  0

n=10000
높이 n/2=5000

배열터짐 배열2개만 가지고 있으면 됨 -> n/2*2=n



*/