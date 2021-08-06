#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

using namespace std;

void solution(int n) {
	int idx = 0;
	while (n != 0) {
		if (n % 2 == 1) {
			printf("%d ", idx);
		}
		n /= 2;
		idx++;
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int n;
		scanf("%d", &n);
		solution(n);
		printf("\n");
	}
	return 0;
}

/*
13
6 1
3 0
1 1
0 1
*/