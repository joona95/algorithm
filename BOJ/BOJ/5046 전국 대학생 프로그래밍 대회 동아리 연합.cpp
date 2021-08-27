#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

using namespace std;

int n, b, h, w;
int p;
int min;

int main() {
	scanf("%d %d %d %d", &n, &b, &h, &w);
	min = b+1;
	for (int i = 0; i < h; i++) {
		scanf("%d", &p);
		for (int j = 0; j < w; j++) {
			int a;
			scanf("%d", &a);
			if (n <= a && min > n*p) {
				min = n * p;
			}
		}
	}
	if (min == b+1) {
		printf("stay home");
		return 0;
	}
	printf("%d", min);
	return 0;
}

/*
scanf 받는 도중에 continue, break 등을 넣어버렸더니 문제가 생겼었다!
*/