/*
#include <cstdio>
#include <cmath>

long long *tree;

class SegmentTree {
public:
	long long length;
	
	SegmentTree(){
		tree=new long long[(long long)pow(2,(int)((log(1000001)/log(2))+2))];
		length=(long long)pow(2,(int)((log(1000001)/log(2))+2));
		
		for(int i=0;i<length;i++){
			tree[i]=0;
		}
	}
 
	
	//int makeTree(int node, int left, int right){
	//}
	
	
//            5
//     5          0
//  2     3     0    0
//2  0  3  0  0  0  0  0
//1  2  3  4  5  6  7  8
//target:4
 	

	//여기서 문제 
	int query(int node, int left, int right, int target){
		if(left==right){
			return left;
		} 
		else{
			int mid=(left+right)/2;
			
			if(tree[2*node]>=target){
				return query(2*node, left,mid,target);
			}
			else {

				target-=tree[2*node];
				return query(2*node+1,mid+1,right,target);			

			}
		}
	}
	
	void update(int node, int left, int right, int target, int num){
		if(target<left||right<target){
			return;
		}
		else{
			tree[node]+=num;
			if(left==right){
				return;
			}
			else{
			
				int mid=(left+right)/2;
				update(2*node, left,mid,target,num);
				update(2*node+1,mid+1,right,target,num);
				
			}
		}
	}
	
};

 

int main() {

	int n;

	scanf("%d", &n);

	SegmentTree t;
	
	for (int i = 0; i < n; i++) {

		int a, b, c;

		scanf("%d", &a);

 

		if (a == 1) {

			scanf("%d", &b);

			int result = t.query(1,1,1000000,b);
			t.update(1,1,1000000,result,-1);

			printf("%d\n",result);
		}
		else if (a == 2) {

			scanf("%d%d", &b, &c);
			
			t.update(1,1,1000000,b,c);

		}

	}
}
*/


//사탕 상자

/*
구간 합 구하기와 비슷
segment tree
sum구할수 있는데 번째도 구할 수 있음

1~10
1  2  3  4  5  6  7  8  
1  2  1  2  1  1  2  2

    6     /     6
 3  /  3  /  2  /  4 
1  2/ 1  2/ 1  1/ 2  2

query조건이 sum을 구하는게 아니라
왼쪽애들을 다 빼고


 
 ?????????????????
 
 
애초에 diff값이 주어지므로 원본값 저장할 필요가 없음 -> 공간 절약

            5
     5
  2     3
2     3
1  2  3  4  5  6  7  8 

4번째꺼 꺼내고 싶을때
앞에 2개는 필요없으므로 더 탐색할 필요없음
4-2=2
3안에 있고 3 안에 있고 3번째맛이 결과로




int query( int node, int left, int right, int target)
target범위 줄필요가 없음

if(left==right)
	return left
else
	int mid=(left+right)/2;
	if(node*2<tree.length&&tree[node*2]>=target
		return query(node*2,left,mid,target);
	else
		target-=tree[node*2];
		if(node*2+1<tree.length&&tree[node*2+1]>=target)
			return query(node*2+1, mid+1,right,target);
		else
			return 0;
		
		
*/ 
