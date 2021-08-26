#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

using namespace std;

/*
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (n % i == 0) {
			cnt++;
		}
		if (cnt == k) {
			printf("%d", i);
			return 0;
		}
	}
	printf("%d", 0);
	return 0;
}*/


int solution(int n, int k) {
	for (int i = 1; i <= n; i++) {
		if (n%i == 0) {
			k--;
		}
		if (k == 0) {
			return i;
		}
	}
	return 0;
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	printf("%d", solution(n, k));
	return 0;
}

/*
cnt 선언할 필요 없이 k로 처리 가능
함수로 따로 빼주는 게 더 보기 좋은 듯
*/