/*
#include <cstdio>
#include <queue>

using namespace std;

int num[10];
int max=0;



int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	
	int m=0;
	int tmp[10];
	while(n!=0){
		tmp[m]=n%10;
		n/=10;
		m++;
	}
	

	for(int i=1;i<=m;i++){
		num[i]=tmp[m-i];
	}


	queue<int> q;
	q.push(1);
	while(!q.empty())){
		int v=q.front();
		q.pop();
		
		if(count==k){
			
		}
		else{
			
		}
	}
	
	if(m<=1){
		printf("-1");
	}
	else{
		for(int i=1;i<=m;i++){
			printf("%d",num[i]);
		}
	}
	
	return 0;
}
 */
