#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

using namespace std;

/*
int fibonacci[21];

int main() {
	int n;
	scanf("%d", &n);
	fibonacci[0] = 0;
	fibonacci[1] = 1;
	for (int i = 2; i <= n; i++) {
		fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
	}
	printf("%d", fibonacci[n]);
	return 0;
}
*/

//Àç±Í
int fibonacci(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d", fibonacci(n));
	return 0;
}