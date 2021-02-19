#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>

using namespace std;

int a[100001];

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	int x;
	scanf("%d", &x);

	sort(a, a + n);

	int answer = 0;
	for (int i = 0; i < n; i++) {
		int s = i+1, e = n-1;

		while (s<=e) {
			//printf("%d %d %d\n", i, s, e);
			int mid = (s + e) / 2;

			if (a[i] + a[mid] == x) {
				answer++;
				
				break;
			}
			else if (a[i] + a[mid] < x) {
				s = mid + 1;
			}
			else {
				e = mid - 1;
			}
		}
	}

	printf("%d\n", answer);

	return 0;
}