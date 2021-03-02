#define _CRT_SECURE_NO_WARNINGS

//#include <iostream>
//#include <string>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
	int m;
	scanf("%d\n", &m);

	int a = 0;
	for (int i = 0; i < m; i++) {
		char s[10];
		scanf("%s", s);

		if (strcmp(s,"add")==0) {
			int x;
			scanf("%d", &x);
			a |= (1 << x);
		}
		else if (strcmp(s,"remove")==0) {
			int x;
			scanf("%d", &x);
			if ((a & (1 << x)) == (1 << x))
				a ^= (1 << x);
		}
		else if (strcmp(s,"check")==0) {
			int x;
			scanf("%d", &x);
			if ((a & (1 << x)) == (1 << x))
				printf("1\n");
			else
				printf("0\n");
		}
		else if (strcmp(s,"toggle")==0) {
			int x;
			scanf("%d", &x);
			if ((a & (1 << x)) == 1 << x)
				a ^= (1 << x);
			else
				a |= (1 << x);
		}
		else if (strcmp(s,"all")==0) {
			a |= (~0);
		}
		else if (strcmp(s,"empty")==0) {
			a &= 0;
		}
		//printf("%d\n", a);
	}

	return 0;
}

/*
cin, cout 쓰니까 시간초과
*/