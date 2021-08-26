#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

using namespace std;

int n, s;
int arr[100001];

int solve() {
	int answer = 100001;
	int start = 1, end = 1;
	while (start <= end && start <= n && end <= n) {
		if (arr[end] - arr[start - 1] < s) {
			end++;
			continue;
		}
		if (answer > end - start + 1) {
			answer = end - start + 1;
		}
		start++;
	}
	return answer;
}

int main() {
	scanf("%d %d", &n, &s);
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		arr[i] = arr[i - 1] + num;
	}
	int result = solve();
	if (result == 100001) {
		printf("0");
		return 0;
	}
	printf("%d", result);
	return 0;
}

//부분합 - 투포인터