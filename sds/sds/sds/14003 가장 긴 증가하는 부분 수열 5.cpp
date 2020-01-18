#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>

using namespace std;

int arr[1000005];
int dp[1000005];
int p[1000005];
int ans[1000005];

int find(int s, int e, int target) {
	
	while (s < e) {
		int mid = (s + e) / 2;

		if (dp[mid] < target) {
			s = mid + 1;
		}
		else {
			e = mid;
		}
	}

	return e;
}

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}

	int len = 0;
	for (int i = 1; i <= n; i++) {
		if (dp[len] < arr[i]) {
			len++;
			dp[len] = arr[i];
			p[i] = len;
		}
		else if (dp[len] == arr[i]) {
			continue;
		}
		else {
			//printf("len:%d\n", len);
			int idx = find(1, len, arr[i]);
			//printf("%d - idx:%d\n",arr[i], idx);
			dp[idx] = arr[i];
			p[i] = idx;
		}
	}
	
	/*
	for (int i = 1; i <= n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	for (int i = 1; i <= n; i++) {
		printf("%d ", p[i]);
	}
	printf("\n");
	for (int i = 1; i <= n; i++) {
		printf("%d ", dp[i]);
	}*/

	printf("%d\n", len);

	int idx = len;
	for (int i = n; i >0; i--) {
		if (idx == p[i]) {
			ans[idx--] = arr[i];
		}
	}

	for (int i = 1; i <=len; i++) {
		printf("%d ", ans[i]);
	}

	return 0;
}

/*
12 5 14 3 19 4 6 12 5 8

바이너리서치 또는 인덱스트리 -> NlogN 가능

10 20 10 30 20 50

1 6 2 5 7 3 5 6
0 1 1 2 3 2 3 4

12356

1 6 2 5 7 3 5 6
1 2 2 3 4 3 4 5

1 2 3 5 6

*/
