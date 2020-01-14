/*
#include <cstdio>

int dp[31][31];

int program(int n, int m){
	if(n==m||m==0){
		dp[n][m]=1;
		return 1;
	}
	else{
		int result=0;
		if(dp[n-1][m-1]!=0){
			result+=dp[n-1][m-1];
		}
		else{
			result+=program(n-1,m-1);
		}
		
		if(dp[n-1][m]!=0){
			result+=dp[n-1][m];
		}
		else{
			result+=program(n-1,m);
		}
		
		dp[n][m]=result;
		return result;
		
	}
}

int main(){
	int t;
	scanf("%d",&t);
	
	for(int i=0;i<t;i++){
		int n,m;
		scanf("%d%d",&n,&m);
		
		int result = program(m,n);
		printf("%d\n",result);
	}
	
	return 0;
}
*/

//mCn ±¸ÇÏ±â 
