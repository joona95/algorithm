#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

bool arr[1001];

int main() {
	int n, k;
	scanf("%d%d", &n, &k);

	int count = 0;
	for (int i = 2; i <= n; i++) {
		if (arr[i] == false) {
			arr[i] = true;
			count++;

			if (count == k) {
				printf("%d", i);
				return 0;
			}

			int num = i * 2;
			while (num <= n) {
				if (arr[num] == false) {
					arr[num] = true;
					count++;

					if (count == k) {
						printf("%d", num);
						return 0;
					}
				}
				num += i;
			}
		}
	}

	return 0;
}




/*
10 7

2 4 6 8 10
3 9
5
7

*/
