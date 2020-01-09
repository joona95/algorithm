/*
#include <cstdio>
#include <cmath>

int gcd(int a, int b){
	while(b!=0){
		int tmp=a%b;
		a=b;
		b=tmp;
	}
	
	return abs(a);
}

int main(){
	int a,b,c,d;
	scanf("%d%d",&a,&b);
	scanf("%d%d",&c,&d);
	
	int A,B;
	B=b*d;
	A=a*d+c*b;
	
	int g = gcd(A,B);
	
	printf("%d %d",A/g,B/g);
	
	return 0;
}
*/


/*
유클리드 호제법
gcd(a,b)=gcd(b, a%b)

int gcd(int a, int b){
	while(b!=0){
		int tmp=a%b;
		a=b;
		b=tmp;
	}
	return Math.abs(a);
}
*/
