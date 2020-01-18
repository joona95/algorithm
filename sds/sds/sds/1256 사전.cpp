
#include <cstdio>

int dp[201][201];

int countProgram(int a, int b){
	if(a==b || b==0){
		dp[a][b]=1;
		return 1;
	} 
	else{
		int result=0;
		if(dp[a-1][b-1]!=0){
			result+=dp[a-1][b-1];
		}
		else{
			result+=countProgram(a-1,b-1);
		}
		
		if(dp[a-1][b]!=0){
			result+=dp[a-1][b];
		}
		else{
			result+=countProgram(a-1,b);
		}
		
		if(result>=1e9)
			result=1e9;
		
		dp[a][b]=result;
			
		return result;
	} 
}
//dp만들때 10억 넘으면 10억으로 바꿔줘도 상관없음 

void dictionary(int a, int b, int k){
	
	//printf("\n%d %d %d\n%d %d\n",a,b,k,dp[a-1][b],dp[a-1][b-1]);
	
	if(a-1==0){
		if(a-1>=b)
			printf("a");
		else
			printf("z");
	}
	
	if(a-1>0){
		if(dp[a-1][b]>=k ){
			printf("a");
			dictionary(a-1,b,k);
		}
		else{
			printf("z");
			dictionary(a-1,b-1,k-dp[a-1][b]);
		}
	}
}

int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	
	int total = countProgram(n+m,m); //n+mCm 전체에서 z를 m개 고른 경우 
	
	//printf("%d\n",total);
	if(total<k){
		printf("-1");
		return 0;
	}
	
	dictionary(n+m, m, k);
	
	return 0;
}


/*
점화식

a을 선택한 케이스 /z를 선택한 케이스
5C3 5개 중 z 3개를 고른 경우 
a를 골랐을 때: 4C3 -> a고를수있는 케이스 3C3 + z 고를 수 있는 케이스 3C2 
z를 골랐을 때: 4C2 
dp에 값 다 저장
 
단어 depth 만에 찾을 수 있음 
 
7
4 -> 1
     3 -> 1
          2 -> 1
               1
6 -> 3 -> 1
          2 -> 1
               1
     3
7
5 3
4 3                          4 2
3 3  3 2                     3 2            3 1
     2 2  2 1                2 2  2 1
	      1 1  1 0                1 1  1 0
	      							   0 0  0 -1
		   
2 2 2
2개의 a
2개의 z
2번째 문자 


4 2
3 1 z         , 3 2 a
2 0, 2 1       2 1            , 2 2
     1 0 1 1   1 0, 1 1
                    0 0 0 1
                        

if n+m==0
	return
else if n==0
	printf("z");
else if m==0
	printf("a");
else
	a와 z 선택 둘 다 가능할 때 


*/
