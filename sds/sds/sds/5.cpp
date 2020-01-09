#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>
using namespace std;

int stu[105];
int rec[25];
int cnt[105];

bool cmp(int a, int b){
	if(stu[a]<stu[b]){
		return false;
	}
	else if(stu[a]>stu[b]){
		return true;
	}
	else if(stu[a]==stu[b]){
		return cnt[a]>cnt[b];
	}
}

int main(){
	int n,r;
	scanf("%d%d",&n,&r);
	
	int c=1;
	int idx=-1;
	for(int i=0;i<r;i++){
		int s;
		scanf("%d", &s);
		
		if(idx<n-1){
			bool find=false;
			for(int j=0;j<=idx;j++){
				if(rec[j]==s){
					find=true;
					stu[s]++;
					if(cnt[s]==0)
						cnt[s]=c;
				}			
			}
			
			
			if(find==false){
				idx++;
				rec[idx]=s;
				stu[s]++;
				if(cnt[s]==0)
					cnt[s]=c;
			}
			
			//printf("rec:%d stu:%d idx:%d\n", rec[idx],stu[s],idx);
			
		}
		else{
			sort(rec, rec+n, cmp);
			
			bool find=false;
			for(int j=0;j<=idx;j++){
				if(rec[j]==s){
					find=true;
					stu[s]++;
					if(cnt[s]==0)
						cnt[s]=c;
				}
			}
			
			if(find==false){
				stu[rec[idx]]=0;
				cnt[rec[idx]] = 0;
				rec[idx]=s;
				stu[s]++;
				if(cnt[s]==0)
					cnt[s]=c;
			}
		}
		
		c++;
	
		/*
		printf("****\n");	
		for(int i=0;i<=idx;i++){
			printf("%d ",rec[i]);
		}
		printf("\n****\n");
		*/
	}
	
	sort(rec,rec+idx+1);
	
	for(int i=0;i<=idx;i++){
		printf("%d ",rec[i]);
	}
	printf("\n");
	
	/*
	for (int i = 0; i <= idx; i++) {
		printf("%d ", stu[rec[i]]);
	}
	printf("\n");
	*/
	return 0;
} 

/*
2 1 4 3 5 6 2 7 2
2 1 4
4 1 3
3 4 5
5 3 6
6 5 2
2 6 7

FIFO임 가장 최근에 사용되지 않은 것이 나가는게 아님 문제 제대로 읽자

*/
