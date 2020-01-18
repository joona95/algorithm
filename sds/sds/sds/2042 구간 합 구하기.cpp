
#include <cstdio>
#include <cmath>

class segmentTree{
public:
	long long *nums;
	long long *tree;
	
	segmentTree(int n){
		nums=new long long[n+5];
		tree=new long long[(int)(log(n)/log(2))*n+5];
		for(int i=1;i<=pow(2,(int)(log(n)/log(2))+1)+5;i++)
			tree[i]=0;
	
	};
	
	long long makeTree(int node, int left, int right){
		if(left==right){
			//printf("node:%d left:%d\n",node,nums[left]);
			return tree[node]=nums[left];
		}
		
		int mid=(left+right)/2;
		
		tree[node]+=makeTree(node*2,left, mid);
		tree[node]+=makeTree(node*2+1,mid+1,right);
		
		//printf("node:%d tree[node]:%d\n",node, tree[node]);
		
		return tree[node];
	}
	
	long long query(int node, int left, int right, int targetLeft, int targetRight){
		//printf("l:%d r:%d n:%d -> %d\n, %d %d",left,right,node,tree[node],targetLeft,targetRight);
		if(targetRight<left || targetLeft>right){
			//printf("%d %d\n",left,right);
			return 0;
		}
		else if(targetLeft<=left&&right<=targetRight){
			//printf("%d %d %d %d\n",left,right,node,tree[node]);
			return tree[node];
		}
		else{
			int mid=(left+right)/2;
			long long result= query(node*2, left, mid, targetLeft, targetRight)+query(node*2+1, mid+1,right,targetLeft,targetRight);
			return result;
			
		}
	}
	
	void update(int node, int left, int right, int targetIndex, long long diff){
		if(targetIndex<left || targetIndex>right){
			return;
		}
		else{
			tree[node]+=diff;
			if(left==right){
				return;
			}
			else{
				int mid=(left+right)/2;
				update(node*2, left, mid, targetIndex, diff);
				update(node*2+1,mid+1,right,targetIndex, diff);
			}
		}
		
	}
	
	
};

int main(){
	int n, m, k;
	scanf("%d%d%d",&n,&m,&k);
	
	segmentTree t=segmentTree(n);
	
	for(int i=1;i<=n;i++){
		scanf("%lld",&t.nums[i]);
	}

	
	t.makeTree(1,1,n);
	
	for(int i=1;i<=m+k;i++){
		int a,b;
		long long c;
		scanf("%d%d%lld",&a,&b,&c);
		
		if(a==1){
			//b를 c로 변경 
			long long diff = c-t.nums[b];
			t.update(1,1,n,b,diff);
			t.nums[b]=c;
		}
		else if(a==2){
			//b부터 c까지의 합 
			long long result = t.query(1,1,n,b,c);
			printf("%lld\n",result);
		}
	}
	
	return 0;
}


//makeTree(iny node, int left, int right)
//update(int node,int left, int right, int targetIndex, long diff)
//query(int node, int left, int right, int targetLeft, targetRight) -> 1,1,8,1,4



