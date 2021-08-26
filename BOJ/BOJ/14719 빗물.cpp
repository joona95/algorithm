#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

using namespace std;

int h, w;
int arr[501];

/*
2~w-1까지
왼쪽 max, 오른쪽 max 높이 중 더 작은 값 - 현재 높이
*/

int max(int a, int b) {
	if (a > b) { return a; }
	return b;
}

int min(int a, int b) {
	if (a > b) { return b; }
	return a;
}

int solution() {
	int answer = 0;
	for (int i = 2; i < w; i++) {
		int l, r;
		l = r = arr[i];
		for (int j = 1; j < i; j++) {
			l = max(l, arr[j]);
		}
		for (int j = i+1; j <= w; j++) {
			r = max(r, arr[j]);
		}
		answer += min(l, r) - arr[i];
	}
	return answer;
}

int main() {
	scanf("%d %d", &h, &w);

	for (int i = 1; i <= w; i++) {
		scanf("%d", &arr[i]);
	}

	printf("%d", solution());
	return 0;
}