#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

using namespace std;

int a[50];
int b[50];

int main() {
	int k;
	scanf("%d", &k);

	a[0] = 1;
	b[0] = 0;

	for (int i = 1; i <= k; i++) {
		a[i] = b[i-1];
		b[i] = b[i-1]+a[i-1];
	}

	printf("%d %d", a[k], b[k]);

	return 0;
}