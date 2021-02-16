#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>

using namespace std;

int f[100001];

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &f[i]);
	}

	sort(f, f + n);

	int answer = 0;
	for (int i = 0; i < n; i++) {
		int s = i+1, e = n - 1;
		
		while (s <= e) {
			
			int mid = (s + e) / 2;

			if ((float)f[i] >= 0.9f * (float)f[mid]) {
				s = mid + 1;
				//printf("1) %d: %d %d\n", i, s, e);
			}
			else {
				e = mid - 1;
				//printf("2) %d: %d %d\n", i, s, e);
			}
		}
		//printf("s:%d e:%d i:%d\n", s, e, i);
		answer += e - i;
	}

	printf("%d", answer);

	return 0;
}