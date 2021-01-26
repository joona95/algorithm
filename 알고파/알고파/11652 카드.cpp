#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>

using namespace std;

long long arr[100001];

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}

	sort(arr, arr + n);

	long long answer = arr[0];
	long long num = arr[0];
	int max = 1;
	int cnt = 1;
	for (int i = 1; i < n; i++) {
		if (num == arr[i]) {
			cnt++;
		}
		else {
			if (max < cnt) {
				max = cnt;
				answer = arr[i - 1];
			}
			num = arr[i];
			cnt = 1;
		}
	}

	if (max < cnt) {
		max = cnt;
		answer = arr[n - 1];
	}

	printf("%lld", answer);

	return 0;
}

/*
�� �������� �����Ͱ� ������ �񱳰� �̷������ �����Ƿ�
for���� �� ������ �� �� �� �� ����� ����.
*/