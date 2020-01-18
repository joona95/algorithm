
#include <cstdio>

long long arr[95];

int main(){
	int n;
	scanf("%d",&n);
	
	arr[0]=0;
	arr[1]=1;
	for(int i=2;i<=n;i++){
		arr[i]=arr[i-1]+arr[i-2];
		printf("%lld ",arr[i]);
	}	
	
	printf("\n%lld",arr[n]);
		
	return 0;
}


/*
0 1 1 2 3 5 8 13  21 34 55 89 144 233 377 610 987 1597

0 1

*/
