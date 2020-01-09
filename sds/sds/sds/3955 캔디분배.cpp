#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cmath>

int k,c;

int gcd(int a, int b){
	while(b!=0){
		int tmp = a%b;
		a=b;
		b=tmp;
	}	
	return abs(a);
}

void ExtendedEuclidean(int Old_s, int Old_t, int Old_r, int s,int t, int r){
	while(r!=0){
		//printf("%d %d %d\n%d %d %d\n",Old_s,Old_t,Old_r,s,t,r);
		int q = Old_r/r;

		int tmp_r=Old_r-q*r;
		Old_r=r;
		r=tmp_r;
		
		int tmp_s=Old_s-q*s;
		Old_s=s;
		s=tmp_s;
		
		int tmp_t=Old_t-q*t;
		Old_t=t;
		t=tmp_t;
		
		
		//printf("%d %d %d %d\n\n",s,t,r,q);
	}
	
	//
	while(!(Old_t>0&&Old_s<0)){
		Old_s-=c;
		Old_t+=k;
	}
	
	if(Old_t>1000000000){
		printf("IMPOSSIBLE\n");
	}
	else{
		printf("%d\n",Old_t);
	}
	//Old_s, Old_t -> x, y
}

int main(){
	int t;
	scanf("%d",&t);
	
	for(int i=0;i<t;i++){
		
		scanf("%d%d",&k,&c);
		
		int g = gcd(k, c);
		//printf("%d\n",g);
	
		if(1%g!=0){
			printf("IMPOSSIBLE\n");
		}
		else{
			ExtendedEuclidean(1,0,k,0,1,c);
		}
	}
	
	
	return 0;
} 


/*
kx+1=cy
-kx+cy=1
ax+by=c

c가 gcd(a,b)로 나눠지면 해가 있고 없으면 해가 없음
gcd가 1이 안나오면 해가 없음

x,y는 양수여야함
y는 10^9보다 작은 범위 안에서 t값 


452929 4711

음수나눌때 나머지는 양수로 나와야한다 

k*(-1*x)+cy=1
x<0


*/
