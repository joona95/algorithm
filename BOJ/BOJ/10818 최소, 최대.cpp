#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	int min = 1000001;
	int max = -1000001;

	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);

		if (min > num) {
			min = num;
		}
		if (max < num) {
			max = num;
		}
	}

	printf("%d %d", min, max);

	return 0;
}