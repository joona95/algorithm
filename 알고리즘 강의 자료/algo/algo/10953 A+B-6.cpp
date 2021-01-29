#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		int a, b;
		scanf("%d,%d", &a, &b);

		printf("%d\n", a + b);
	}

	return 0;
}

/*
cinÀÇ °æ¿ì:
int a,b;
char c;
cin>>a>>c>>b;
*/