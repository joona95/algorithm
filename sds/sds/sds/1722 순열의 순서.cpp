#define _CRT_SECURE_NO_WARNINGS	

#include <cstdio>

int nums[25];
long long fac[25];
bool visited[25];

void test1(int n, long long k){
	//for depth
	//�� depth ���� for������ �湮�� �������� �ƴ��� -> target�� �� ũ�� target���� ���� ����
	
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
	//depth�� �ش��ϴ� ���ڵ��� �����ͼ� result�� �����ָ��
	//result+1������ �������
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
���� ���� �� ���ؼ� �˾Ƴ��� ���� �ƴ϶� depth��ŭ�� Ž���ؼ� ã�ư� �� ���� 

���丮�� O(n) �迭�� ���� 
21! long �Ѿ 

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
