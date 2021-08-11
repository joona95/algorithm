#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>

using namespace std;

int arr[11];

int main() {
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		for (int j = 1; j <= 10; j++) {
			scanf("%d", &arr[j]);
		}
		sort(arr, arr + 11);
		printf("%d\n", arr[8]);
	}

	return 0;
}

//구현, 정렬