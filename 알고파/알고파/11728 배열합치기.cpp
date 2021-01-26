#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>

using namespace std;

int arr[2000001];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n+m; i++) {
		scanf("%d", &arr[i]);
	}
	
	sort(arr, arr + (n + m));

	for (int i = 0; i < n + m; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}