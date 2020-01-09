/*
#include <cstdio>

int tree[1000005];

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int max_tree=0;
	for(int i=0;i<n;i++){
		scanf("%d",&tree[i]);
		if(max_tree<tree[i]){
			max_tree=tree[i];
		}
	}
	
	int s=1, e=max_tree;
	
	int max_h=0;
	while(s<e){
		int mid = (s+e)/2;
		
		long long sum=0;
		for(int i=0;i<n;i++){
			if(tree[i]>mid){
				sum+=(tree[i]-mid);
			}
		}
		
		if(sum==m){
			if(max_h<mid)
				max_h=mid;
			break;
		}
		else if(sum>m){
			s=mid+1;
			if(max_h<mid)
				max_h=mid;
		}
		else if(sum<m){
			e=mid;
			
		}
		
	}
	
	
	printf("%d",max_h);
	
	return 0;
} 
*/

/*
4 7
20 15 10 17

(1,20) 10: 10 5 7 = 22
(10,20) 15: 5 2 = 7

*/
