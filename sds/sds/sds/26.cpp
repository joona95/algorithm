/*
#include <cstdio>

int program(int n, int k){
	//printf("%d %d\n",n,k);
	if(n==k || k==0){
		return 1;
	}
	else
		return program(n-1,k-1)+program(n-1,k);
	
}

int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	
	int result = program(n,k);
	printf("%d\n",result);
}
*/


/*

5,2
4,1 4,2
    3,1 3,2
        2,1 2,2
            1,0 1,1
            
            
������ ����ϸ� �ð��ʰ� �Ͼ �� ���� -> ĳ��

6C3 -> dp[6][3] 

*/

//nCk
