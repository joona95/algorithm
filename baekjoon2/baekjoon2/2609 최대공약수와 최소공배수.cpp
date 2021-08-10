#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

using namespace std;

//유클리드 호제법
/*
int gcd(int a, int b) {
	int r = a % b;
	if (r == 0)
		return b;
	return gcd(b, r);
}*/

int gcd(int a, int b) {
	int r = a % b;
	while (r != 0) {
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d\n%d\n", gcd(a,b), lcm(a,b));
	return 0;
}