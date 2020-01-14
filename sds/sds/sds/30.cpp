#define _CRT_SECURE_NO_WARNINGS	

#include <cstdio>

int nums[25];
long long fac[25];
bool visited[25];

void test1(int n, long long k){
	//for depth
	//각 depth 마다 for문으로 방문된 숫자인지 아닌지 -> target이 더 크면 target에서 값을 뺀다
	
	for(int d=0;d<n;d++){
		for(int i=1;i<=n;i++){
			if(visited[i]){
				continue;
			}
			else {
				if (d==n-1) {
					printf("%d\n", i);
				}
				else if (fac[n - d - 1] < k) {
					k -= fac[n - d - 1];
					//printf("%d\n", k);
				}
				else {
					visited[i] = true;
					printf("%d ", i);
					break;
				}
			}
		}
	}
}

long long test2(int n){
	//depth에 해당하는 숫자들을 꺼내와서 result값 더해주면됨
	//result+1값으로 해줘야함
	long long result = 0;
	for (int d = 0; d <n; d++) {
		for (int i = 1; i <= n; i++) {
			if (visited[i] == false) {
				if (i == nums[d]) {
					visited[i] = true;
					break;
				}
				else
					result += fac[n - d - 1];
			}
		}
	}

	result += 1;
	
	return result;
	
}

int main(){
	int n,t;
	scanf("%d%d",&n,&t);
	
	//factorial
	long long result=1;
	for(int i=1;i<=n;i++){
		result*=i;
		fac[i]=result;		
	}
	
	if(t==1){
		long long k;
		scanf("%lld",&k);
		
		test1(n,k);
	}
	else if(t==2){
		for(int i=0;i<n;i++){
			scanf("%d",&nums[i]);
		}
		
		printf("%lld", test2(n));
	}
	
	return 0;
} 

/*
순열 전부 다 구해서 알아내는 것이 아니라 depth만큼만 탐색해서 찾아갈 수 있음 

팩토리얼 O(n) 배열에 저장 
21! long 넘어감 

1 2 3 4
    4 3

3
24 6 2 1
       1
     2 1
       1
     2 1
       1
   6
   6
   6 
   
1 4 3
2 3 3


*/
