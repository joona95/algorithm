#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

using namespace std;

//배열없이 1112KB
int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	
	int sum = 0, bottomSum=0;
	int c = 1;
	for (int i = 1; i <= b; i += c++) {
		for (int j = 0; j < c; j++) {
			sum += c;
			if (a - 1 == i + j) {
				bottomSum = sum;
			}
			if (b == i + j) {
				break;
			}
		}
	}
	printf("%d", sum - bottomSum);

	return 0;
}

/*
//배열 선언 1116KB
int arr[1001];

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	int c = 1;
	for (int i = 1; i <= b; i+=c++) {
		for (int j = 0; j < c; j++) {
			arr[i + j] = arr[i+j-1] + c;
		}
	}
	printf("%d", arr[b] - arr[a - 1]);

	return 0;
}
*/

//구간합