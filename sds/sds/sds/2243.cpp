#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

class SegmentTree {
public:

};

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int a, b, c;
		scanf("%d", &a);

		if (a == 1) {
			scanf("%d", &b);
		}
		else if (a == 2) {
			scanf("%d%d", &b, &c);
		}
	}

}

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
