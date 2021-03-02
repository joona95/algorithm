#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		
		for (unsigned char x = 0; x <= 255; x++) {
			if (((x^(x<<1)) & 255) == num) {
				printf("%d ", x);
				break;
			}
		}
	}

	return 0;
}