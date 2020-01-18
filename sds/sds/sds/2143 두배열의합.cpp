
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
	
	long long result=0; //�κ��� n! ������ long long ������ �Ѿ �� �� 
	int upper;
	for(int i=0;i<sum_A.size();i++){
		int s=0, e=sum_B.size();
		while(s<e){
			int mid = (s+e)/2;
			//printf("s:%d mid:%d e:%d\n",s,m��id,e);
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




//parametric search ���� -> upper bound, lower bound 

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

A�� B�� �κ��� ���� �̸� ���� lower, upper bound �̿��ؼ� ��� ���� ���� ���� �� �����Ƿ� 
while�� ���� �� ã���� n��ŭ ���� �� ������ ��ȿ����
upper bound, lower bound ����ؼ� �ϸ� �� ����
 
A�� B�迭�� �����.
���� for�� ���鼭 ��� ���̽��� �� ������� -> A B�� ��� �κ��� ����
B �迭�� �������� 
A��ŭ �����ָ鼭 �ϳ� �����鼭 B���� �ش��ϴ� lower bound ���� upper bound�� ����
upper bound-lower bound�ϸ� �� �� �ִ��� ����
 
1 2 3 3 3 4 5 
    *     *
3�� ã���� 
lower�� �̻��� ���� ó�� ������ ��
upper�� �ʰ��� ���� ó�� ������ ��
 
1 2 3 3 3 5 6
          * <-lower, upper
4�� ã�� ��
upper-lower=0

while(s<e)
upper
������
s=mid+1
Ŭ ��
e=mid
���� ��
s=mid+1

lower
���� ��
s=mid+1
Ŭ ��
e=mid
���� ��
e=mid 

*/
