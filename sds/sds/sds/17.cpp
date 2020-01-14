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
 	

	//���⼭ ���� 
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


//���� ����

/*
���� �� ���ϱ�� ���
segment tree
sum���Ҽ� �ִµ� ��°�� ���� �� ����

1~10
1  2  3  4  5  6  7  8  
1  2  1  2  1  1  2  2

    6     /     6
 3  /  3  /  2  /  4 
1  2/ 1  2/ 1  1/ 2  2

query������ sum�� ���ϴ°� �ƴ϶�
���ʾֵ��� �� ����


 
 ?????????????????
 
 
���ʿ� diff���� �־����Ƿ� ������ ������ �ʿ䰡 ���� -> ���� ����

            5
     5
  2     3
2     3
1  2  3  4  5  6  7  8 

4��°�� ������ ������
�տ� 2���� �ʿ�����Ƿ� �� Ž���� �ʿ����
4-2=2
3�ȿ� �ְ� 3 �ȿ� �ְ� 3��°���� �����




int query( int node, int left, int right, int target)
target���� ���ʿ䰡 ����

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
