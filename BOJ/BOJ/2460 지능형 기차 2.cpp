#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

using namespace std;

int main() {
	int max = 0;
	int sum = 0;
	int on, off;
	while (scanf("%d %d\n", &off, &on)!=EOF) {
		sum = sum - off + on;
		if (sum > max) {
			max = sum;
		}
	}

	printf("%d", max);

	return 0;
}