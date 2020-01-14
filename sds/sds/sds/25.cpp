
/*
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

bool arr[1000001];
vector<int> v;


int main(){
	char P[105];
	int K;
	scanf("%s",&P);
	scanf("%d",&K);
	
	for(int i=2;i<=1000000;i++){
		if(arr[i]==false){
			arr[i]=true;
			v.push_back(i);
			
			int num=i*2;
			while(num<=1000000){
				if(arr[num]==false)
					arr[num]=true;
				num+=i;
			}
		}
	}
	

	
	for(int i=0;i<v.size();i++){
		long long n=0,r;
		for(int j=0;j<strlen(P);j++){
			n += P[j]-'0';
			r = n%v[i];
			
			if(j==strlen(P)-1){
				if(r==0){
					int p=v[i];
					//int q=atoi(P)/v[i];
					//printf("%d %d\n",p,q);					
	
					if(p<K){
						printf("BAD %d\n",p);
							
					}
					else{
						printf("GOOD\n");
					}
						
					return 0;
					
				}
			}
			
			r*=10;
			n=r;
		}
	}
	
	printf("GOOD\n");
	
	return 0;
} 
*/

/*
숫자를 char로 표현

1 2 3 4 5 6 7

1/2 -> 나머지 1
1*10 + 2   /  2  -> 나머지
나머지*10 + 3   /  2  -> 나머지 
.
.
.

string 으로 modular연 


check 함수를 따로 구현하는거 추천 -> test가 편함 
 
 
*/
