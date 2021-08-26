#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cmath>

using namespace std;

/*
bool isPrime(int num) {
	if (num == 1)
		return false;

	for (int j = 2; j < num; j++) {
		if (num%j == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int n;
	scanf("%d", &n);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);

		if (isPrime(num)) {
			cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}
*/

//에라토스테네스의 체
/*
bool isPrime(int num) {
	if (num == 1)
		return false;
	for (int i = 2; i <= sqrt(num); i++) {
		for (int j = i * i; j <= num; j += i) {
			if (j == num)
				return false;
		}
	}
	return true;
}

int main() {
	int n;
	scanf("%d", &n);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);

		if (isPrime(num)) {
			cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}
*/

bool prime[1001];

void initArr(int num) {
	for (int i = 2; i <= num; i++) {
		prime[i] = true;
	}
}

void findPrime(int num) {
	for (int i = 2; i <= sqrt(num); i++) {
		if (!prime[i])
			continue;
		for (int j = i * i; j <= num; j+=i) {
			prime[j] = false;
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		initArr(num);
		findPrime(num);
		if (prime[num]) {
			cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}

/*
이 문제처럼 숫자가 작은 경우에는 제일 처음 꺼가 메모리 1112KB로 가장 적게 들긴 함.
에라토스테네스의 체=> 두번째 경우는 메모리 저장을 따로 안해서 넘어가지를 못하니까 결국 더 오래걸림 (1128KB)
아예 넘어갈 수 있게 한 경우에는 전체 prime판별 배열 선언으로 메모리 저장을 더 해서 그런지 1128KB 가 나옴.
*/