/*
#include <cstdio>

int arr[100005];

int main(){
	int N;
	long long S;
	scanf("%d%lld",&N,&S);
	
	for(int i=0;i<N;i++){
		scanf("%d",&arr[i]);
	}
	
	int s=0, e=0;
	
	int min=N+1;
	long long sum=arr[0];
	while(true){
		if(sum==S){
			if(min>(e-s+1)){
				min=e-s+1;
			}
			
			sum-=arr[s++];
			
		}
		else if(sum>S){
			if(min>(e-s+1)){
				min=e-s+1;
			}
			
			sum-=arr[s++];
			if(s>=N)
				break;
			
			
		}
		else if(sum<S){
			sum+=arr[++e];
			if(e>=N)
				break;
		}
		
		if(s>e){
			sum+=arr[++e];
			if(e>=N)
				break;
		}
		
		printf("%d %d %lld\n",s,e,sum);
	}
	
	if(min==N+1){
		printf("0");
	}
	else{
		printf("%d", min);
	}
	
	return 0;
}
*/

//그 합이 S'이상'이 되는 것 중~ 

/*
10 15
5 1 3 5 10 7 4 9 2 8

5
5 1
5 1 3
5 1 3 5
5 1 3 5 10
1 3 5 10
3 5 10
5 10 *
10
10 7
7 
7 4
7 4 9
4 9
4 9 2 *
9 2 
9 2 8
2 8


*/
