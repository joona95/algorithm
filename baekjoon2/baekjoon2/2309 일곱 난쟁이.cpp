#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>

using namespace std;

int sum;
int arr[9];

//¡ﬂ√∏ ¡Ÿ¿Ã±‚
int Solution(int* arr) {
	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (sum - arr[i] - arr[j] == 100) {
				arr[i] = -1;
				arr[j] = -1;
				return 0;
			}
		}
	}
}

int main() {
	for (int i = 0; i < 9; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}

	Solution(arr);

	sort(arr, arr + 9);

	for (int i = 2; i < 9; i++) {
		printf("%d\n", arr[i]);
	}
}

/*
int main() {
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}

	sort(arr, arr + 9);

	
	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (sum - arr[i] - arr[j] == 100) {
				for (int k = 0; k < 9; k++) {
					if (k != i && k != j) {
						printf("%d\n", arr[k]);
					}
				}
				return 0;
			}
		}
	}

	return 0;
}
*/

/*
7 8 10 13 15 19 20 23 25
*/