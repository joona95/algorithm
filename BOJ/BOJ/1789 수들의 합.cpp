#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

using namespace std;

long long s;

long long solve() {
	long long num = 1;
	long long sum = 0;
	while (1) {
		sum += num;
		if (sum > s) {
			num--;
			break;
		}
		num++;
	}
	return num;
}

int main() {
	scanf("%lld", &s);
	printf("%lld", solve());
	return 0;
}

/*
와 너무 복잡하게 생각했다.
하나씩 순차적으로 다 더해준다음 s보다 커졌을 때 그 해당 값 하나를 빼면 되는 거였음;
*/