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
