#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int *arr = new int[n];
	int min=0, max = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	sort(arr, arr + n);

	int mid, len=0;
	while (min<=max) {
		mid = (min + max) / 2;
		printf("%d %d %d\n",min ,max, mid);
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			if(arr[i]-mid>0)
				sum += arr[i] - mid;
		}

		if (sum>=m && len<mid) {
			len = mid;
		}

		if (sum < m) {
			max = mid - 1;
		}
		else if (sum > m) {
			min = mid + 1;
		}
		else if (sum == m) {
			break;
		}
	}

	printf("%d", len);

	return 0;
}

/*
답이 항상 mid가 되진 않는다.
반례:
3 1
1 2 2 
답:1 출력:2


*/