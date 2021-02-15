#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	int s = 0, e = 1;
	int sum = 1;
	int answer = 0;
	while (s <= e && e <= n) {
		//printf("s:%d e:%d sum:%d\n", s, e, sum);
		if (sum <= n) {
			if (sum == n) {
				answer++;
			}
			e++;
			sum += e;
		}
		else {
			s++;
			sum -= s;
		}
	}

	printf("%d", answer);

	return 0;
}

/*
얘는 dp 잡으면 메모리 초과
*/