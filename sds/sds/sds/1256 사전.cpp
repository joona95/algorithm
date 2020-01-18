
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
//dp���鶧 10�� ������ 10������ �ٲ��൵ ������� 

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
	
	int total = countProgram(n+m,m); //n+mCm ��ü���� z�� m�� �� ��� 
	
	//printf("%d\n",total);
	if(total<k){
		printf("-1");
		return 0;
	}
	
	dictionary(n+m, m, k);
	
	return 0;
}


/*
��ȭ��

a�� ������ ���̽� /z�� ������ ���̽�
5C3 5�� �� z 3���� �� ��� 
a�� ����� ��: 4C3 -> a�����ִ� ���̽� 3C3 + z �� �� �ִ� ���̽� 3C2 
z�� ����� ��: 4C2 
dp�� �� �� ����
 
�ܾ� depth ���� ã�� �� ���� 
 
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
2���� a
2���� z
2��° ���� 


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
	a�� z ���� �� �� ������ �� 


*/
