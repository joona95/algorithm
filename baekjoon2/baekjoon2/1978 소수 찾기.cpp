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

//�����佺�׳׽��� ü
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
�� ����ó�� ���ڰ� ���� ��쿡�� ���� ó�� ���� �޸� 1112KB�� ���� ���� ��� ��.
�����佺�׳׽��� ü=> �ι�° ���� �޸� ������ ���� ���ؼ� �Ѿ���� ���ϴϱ� �ᱹ �� �����ɸ� (1128KB)
�ƿ� �Ѿ �� �ְ� �� ��쿡�� ��ü prime�Ǻ� �迭 �������� �޸� ������ �� �ؼ� �׷��� 1128KB �� ����.
*/