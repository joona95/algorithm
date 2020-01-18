
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int A[1005];
int B[1005];
vector<int> sum_A;
vector<int> sum_B;

int main(){
	int t,n,m;
	scanf("%d", &t);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d",&B[i]);
	}
	
	
	for(int i=0;i<n;i++){
		int sum=A[i];
		sum_A.push_back(sum);
		for(int j=i+1;j<n;j++){
			sum+=A[j];
			sum_A.push_back(sum);
		}
	}

	for(int i=0;i<m;i++){
		int sum=B[i];
		sum_B.push_back(sum);
		for(int j=i+1;j<m;j++){
			sum+=B[j];
			sum_B.push_back(sum);
		}
	}
	
	
	sort(sum_B.begin(), sum_B.end());
	
	//printf("%d %d\n",sum_A.size(),sum_B.size());
    //1 4 6 3 5 2-> 1 2 3 4 5 6
	//1 2 3 -> 1 3 4 2 5 3 -> 1 2 3 3 4 5
	//1 1 2
	
	long long result=0; //부분합 n! 갯수는 long long 범위로 넘어갈 수 있 
	int upper;
	for(int i=0;i<sum_A.size();i++){
		int s=0, e=sum_B.size();
		while(s<e){
			int mid = (s+e)/2;
			//printf("s:%d mid:%d e:%d\n",s,m음id,e);
			if(t-sum_A[i]>sum_B[mid]){
				s=mid+1;
			}
			else if(t-sum_A[i]<sum_B[mid]){
				e=mid;
			}
			else{
				s=mid+1;
			}
			//printf("->%d s:%d e:%d\n",t-sum_A[i],s,e);
			
		}

		upper=s;
		result+=upper;
		//printf("%d  upper:%d\n",t-sum_A[i],upper);
	}

	
	int lower;
	for(int i=0;i<sum_A.size();i++){
		int s=0, e=sum_B.size();
		while(s<e){
			int mid = (s+e)/2;
			if(t-sum_A[i]>sum_B[mid]){
				s=mid+1;
			}
			else if(t-sum_A[i]<sum_B[mid]){
				e=mid;
			}
			else{
				e=mid;
			}
		}

		
		lower=s;
		result-=lower;
		//printf("%d  lower:%d\n",t-sum_A[i],lower);
	}
	
	
	printf("%lld", result);
	
	return 0;
}




//parametric search 범위 -> upper bound, lower bound 

/*
1 3 1 2
1 3 2

1
1 3

1 3
1

3
2

3 1
1

1
1 3

1 2
2

2 
3

5
3
1 1 1
2 
1 1

*/

/*

A와 B의 부분의 합을 미리 만들어서 lower, upper bound 이용해서 사용 같은 수가 있을 수 있으므로 
while로 같은 수 찾으면 n만큼 같은 수 있으면 비효율적
upper bound, lower bound 사용해서 하면 더 간편
 
A와 B배열을 만든다.
이중 for문 돌면서 모든 케이스를 다 만들어줌 -> A B의 모든 부분합 구함
B 배열만 정렬해줌 
A만큼 돌아주면서 하나 뽑으면서 B에서 해당하는 lower bound 구함 upper bound도 구함
upper bound-lower bound하면 몇 개 있는지 나옴
 
1 2 3 3 3 4 5 
    *     *
3을 찾을때 
lower은 이상인 수가 처음 나오는 곳
upper은 초과한 수가 처음 나오는 곳
 
1 2 3 3 3 5 6
          * <-lower, upper
4를 찾을 때
upper-lower=0

while(s<e)
upper
작을때
s=mid+1
클 때
e=mid
같을 때
s=mid+1

lower
작을 때
s=mid+1
클 때
e=mid
같을 때
e=mid 

*/
