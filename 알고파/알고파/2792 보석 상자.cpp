#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

using namespace std;

int c[300001];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	int low = 1;
	int high = 0;
	for (int i = 0; i < m; i++) {
		scanf("%d", &c[i]);
		if (high < c[i]) {
			high = c[i];
		}
	}

	while (low <= high) {
		int mid = (low + high) / 2;

		int cnt = 0;
		for (int i = 0; i < m; i++) {
			cnt += (c[i] / mid);
			if ((c[i] % mid) != 0) {
				cnt++;
			}
		}

		if (cnt <= n) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}

	printf("%d", low);

	return 0;
}

//ÀÌºÐÅ½»ö