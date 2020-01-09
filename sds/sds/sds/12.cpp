#define _CRT_SECURE_NO_WARNINGS


#include <cstdio>

int arr[100005][3];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &arr[i][0], &arr[i][1], &arr[i][2]);
	}

	
	int max_ans = 0, min_ans = 10000000;
	for (int i = 0; i < 3; i++) {
		int sum = arr[0][i];
		int min[3] = { 10000000, 10000000, 10000000 };
		int max[3] = { 0,0,0 };
		for (int j = 1; j < n; j++) {
			if (0 <= i - 1) {
				if (min[i - 1] > sum + arr[j][i - 1]) {
					min[i - 1] = sum + arr[j][i - 1];
				}
				if (max[i - 1] < sum + arr[j][i - 1]) {
					max[i - 1] = sum + arr[j][i - 1];
				}
			}

			if (min[i] > sum + arr[j][i]) {
				min[i] = sum + arr[j][i];
			}
			if (max[i] < sum + arr[j][i]) {
				max[i] = sum + arr[j][i];
			}

			if (i + 1 < n) {
				if (min[i + 1] > sum + arr[j][i + 1]) {
					min[i + 1] = sum + arr[j][i + 1];
				}
				if (max[i + 1] < sum + arr[j][i + 1]) {
					max[i + 1] = sum + arr[j][i + 1];
				}
			}

			for (int k = 0; k < 3; k++)
				printf("%d ", min[k]);
			printf("\n");
			for (int k = 0; k < 3; k++)
				printf("%d ", max[k]);
			printf("\n***\n");

		}

		for (int j = 0; j < 3; j++) {
			if (min_ans > min[j]) {
				min_ans = min[j];
			}

			if (max_ans < max[j]) {
				max_ans = max[j];
			}
		}
	}
	
	printf("%d %d\n", max_ans, min_ans);

	return 0;
}

/*
1 2 3
4 5 6
4 9 0

1
5 6
9/10 14/15 6
  2
6 7 8
10/11 15/16/17 7/8
    3
  8 9
12 17/18 8/9

*/