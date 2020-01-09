/*
#include <cstdio>
#include <cmath>

int nums[1000005];
int gcd1[1000005];
int gcd2[1000005];

int gcd(int a, int b){
	while(b!=0){
		int tmp=a%b;
		a=b;
		b=tmp;
	}
	
	return abs(a);
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d", &nums[i]);
	}
	
	gcd1[0]=nums[0];
	for(int i=1;i<n;i++){
		gcd1[i] = gcd(nums[i],gcd1[i-1]);
		//printf("%d ",gcd1[i]);
	}
	//printf("\n");
	
	gcd2[n-1]=nums[n-1];
	for(int i=n-2;i>=0;i--){
		gcd2[i]=gcd(nums[i],gcd2[i+1]);
		//printf("%d ",gcd2[i]);
	}
	
	
	int max=0, number=-1;
	for(int i=0;i<n;i++){
		int a=0, b=0;
		if(0<=i-1){
			a=gcd1[i-1];
		}
		
		if(i+1<n){
			b=gcd2[i+1];
		}
		
		int result=gcd(a,b);
		
		if(max<result&&nums[i]%result!=0){
			max=result;
			number=nums[i];
		}
	}
	
	if(number!=-1)
		printf("%d %d",max,number);
	else
		printf("-1");
	
	return 0;
}
*/

/*
3개 24, 36, 48 gcd 구하는 건 (((24,36)의 gcd)와 48)의 gcd ) 구하면 됨
->gcd 
gcd<-
*/
