
#include <cstdio>
#include <utility>
using namespace std;

int n;
//int ans[500005];
//int person[500005];
int cnt[500005];
//int tmp[500005];
pair<int,int> person[500005];
pair<int,int> tmp[500005];

void merge(int s, int m, int e){
	int p1 = s;
	int p2=m+1;
	int k=s;
	
	while(p1<=m&&p2<=e){
		if(person[p1].first<=person[p2].first){
			tmp[k]=make_pair(person[p1].first,person[p1].second);
			k++;
			p1++;
		}
		else{
			tmp[k]=make_pair(person[p2].first,person[p2].second);
			cnt[person[p2].second]+=p1-s;
			k++;
			p2++;

		}
	}
	
	while(p1<=m){
		tmp[k]=make_pair(person[p1].first,person[p1].second);
		k++;
		p1++;
	}
	
	while(p2<=e){
		tmp[k]=make_pair(person[p2].first,person[p2].second);
		cnt[person[p2].second]+=p1-s;
		k++;
		p2++;

	}	
	
	for(int i=s;i<=e;i++){
		person[i].first=tmp[i].first;
		person[i].second=tmp[i].second;
	}
	
}

void Merge_Sort(int s, int e){
	int mid = (s+e)/2;
	if(s<e){
		Merge_Sort(s, mid);
		Merge_Sort(mid+1,e);
		merge(s, mid, e);	
	}
} 


int main(){
	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		int num;
		scanf("%d", &num);
		person[i]=make_pair(num,i);
	}
	
	Merge_Sort(1,n);
	
	for(int i=1;i<=n;i++)
		printf("%d\n",i-cnt[i]);
	
	return 0;
} 


//pair사용하여 idx저장해야함
 

/*
2 8 10 7 1 9 4 15 //더 큰 값이 더 좋은 실력 
1 1 1  3 5 2 5 1

2 8 10 7 1 9 4 15
2 8 10 7/ 1 9 4 15
2 8/ 10 7/1 9/ 4 15
2/8/10/7/1/9/4/15

2 8
7 10
2 7 8 10
1 9
4 15
1 4 9 15
1 2 4 7 8 9 10 15

2 8/ 7 10/ 1 9/4 15
2 7 8 10/1 4 9 15
1 2 4 7 8 9 10 15
5

2 
8 +1
10 +2
7 +1
1 
9 +1 +3
4 +1 +1(p1)
15 +1 +2 +4




10 9 8 7 6 5 4 3 2 1 
10 9 8 7 6/ 5 4 3 2 1
10 9/ 8 7 6 / 5 4 / 3 2 1
10/ 9 /8 /7 6/ 5 /4/3/2 1
10/9/8/7/6/5/4/3/2/1

10/ 9/ 8/ 6 7/ 5/ 4/ 3/ 1 2
9 10/ 6 7 8/ 4 5/ 1 2 3
6 7 8 9 10/ 1 2 3 4 5
1 2 3 4 5 6 7 8 9 10



*/
