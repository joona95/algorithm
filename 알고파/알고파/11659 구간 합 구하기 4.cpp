#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

using namespace std;

int num[100001];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		int k;
		scanf("%d", &k);

		num[i] = num[i - 1] + k;
	}

	int s, e;
	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &s, &e);

		printf("%d\n", num[e] - num[s-1]);
	}

	return 0;
}