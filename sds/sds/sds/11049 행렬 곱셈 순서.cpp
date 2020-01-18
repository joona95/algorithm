//2020.01.15
//11049

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

struct arr {
	int r, c;
};


arr nums[505];
int dp[505][505];


int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int r, c;
		scanf("%d%d", &nums[i].r, &nums[i].c);
	}


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n && j+i-1<=n; j++) {
			for (int k = j; k <j+i-1; k++) {
				if(!dp[j][j+i-1])
					dp[j][j + i - 1] = dp[j][k] + dp[k + 1][j + i - 1] + nums[j].r*nums[k].c*nums[j + i - 1].c;
				else if (dp[j][j + i - 1] > dp[j][k] + dp[k + 1][j + i - 1] + nums[j].r*nums[k].c*nums[j + i - 1].c)
					dp[j][j + i - 1] = dp[j][k] + dp[k + 1][j + i - 1] + nums[j].r*nums[k].c*nums[j + i - 1].c;
			}
		}
	}

	
	printf("%d", dp[1][n]);

	return 0;

}

/*
D[i][j]: i~j 행렬곱했을때 필요한 최소 연산 횟수
D[i][i]=0 초기값


 + ri+ci+cj

5 3
3 2
2 6

0 
0 0 
0 0 0



(((AB)C)D)
(AB)(CD)
(A(BC))D
A((BC)D)
A(B(CD))

  A  B          C               D
0 0  5*3*2      (5*3*2)+5*2*6     5*6*2
     (           3*2*6)+5*3*6


dp[s][e]=dp[s][k]+dp[k+1][e]+nums[s].r*nums[k].c*nums[e].c

if (!dp[i][j])
dp[i][j] = dp[i][k] + dp[k + 1][j] + nums[i].r*nums[k].c*nums[j].c;
else
dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + nums[i].r*nums[k].c*nums[j].c);

*/