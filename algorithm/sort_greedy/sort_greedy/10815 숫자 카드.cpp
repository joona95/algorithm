#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int *arr = new int[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int num;
		scanf("%d", &num);

		int l = 0, r = n - 1;
		bool find = false;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (arr[mid] < num) {
				l = mid + 1;
			}
			else if (arr[mid] > num) {
				r = mid - 1;
			}
			else if (arr[mid] == num) {
				find = true;
				break;
			}
		}

		if (find == false) {
			printf("0 ");
		}
		else {
			printf("1 ");
		}
	}
	
	return 0;
}