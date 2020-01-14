/*
#include <cstdio>

int dp[1001][1001];

int program(int n, int k){
	if(n==k || k==0){
		dp[n][k]=1;
		return 1;
	}
	else{
		int result=0;
		if(dp[n-1][k-1]!=0){
			result+=dp[n-1][k-1];
		}
		else{
			result+=program(n-1,k-1);
		}
		
		if(dp[n-1][k]!=0){
			result+=dp[n-1][k];
		}
		else{
			result+=program(n-1,k);
		}
		
		result%=10007;
		
		dp[n][k]=result;
		
		return result;
		
	}
}

int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	
	int result = program(n,k);
	printf("%d",result);
	
	return 0;
}
*/

/*
10007로 나눈 나머지 출력?
배열에 넣을 때 modular 계산을 하고 넣으면 됨 
*/
