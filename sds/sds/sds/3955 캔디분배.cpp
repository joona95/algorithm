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

c�� gcd(a,b)�� �������� �ذ� �ְ� ������ �ذ� ����
gcd�� 1�� �ȳ����� �ذ� ����

x,y�� ���������
y�� 10^9���� ���� ���� �ȿ��� t�� 


452929 4711

���������� �������� ����� ���;��Ѵ� 

k*(-1*x)+cy=1
x<0


*/
