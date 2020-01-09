/*
#include <cstdio>

int A[10005];
int main(){
	int n;
	long long m;
	scanf("%d%lld",&n,&m);
	
	for(int i=0;i<n;i++){
		scanf("%d",&A[i]);	
	}
	
	int s=0, e=0;
	int count=0;
	long long sum=A[0];
	while(s<=e){
		if(sum<m){
			e++;
			if(e>=n){
				break;
			}
			sum+=A[e];
		}	
		else if(sum>m){
			sum-=A[s];
			s++;
			if(s>=n){
				break;
			}
			
			//***
			if(s>e){
				e++;
				if(e>=n)
					break;
				sum+=A[e];
			}
		}
		else if(sum==m){
			count++;
			sum-=A[s];
			s++;
			if(s>=n)
				break;
		
			//***
			if(s>e){
				e++;
				if(e>=n)
					break;
				sum+=A[e];
			}
		}
	
		printf("%d %d %d\n",s,e,sum);
	}
	
	printf("%d", count);
	
	return 0;
}*/

//�����̵� ������:O(n)
//while���� true �ְ� Ż������ ���� �ֱ� ��õ 

 /*
 10 5
 1 2 3 4 2 5 3 1 1 2
 1
 1 2
 1 2 3
 2 3
 3
 3 4
 4
 4 2
 2
 2 5
 5
 5 3
 3
 3 1
 3 1 1
 1 1
 1 1 2
   
   
 10 1
 2 2 1 2 2 2 1 2 2 2  
 
 */
