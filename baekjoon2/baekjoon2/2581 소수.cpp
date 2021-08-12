#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cmath>

using namespace std;

#define MAX 10000
bool prime[MAX+1];

void initPrime() {
	for (int i = 2; i <= MAX; i++) {
		prime[i] = true;
	}
}

//eratosthenes
void findPrime() {
	for (int i = 2; i <= sqrt(MAX); i++) {
		if (prime[i]) {
			for (int j = i * i; j <= MAX; j += i) {
				prime[j] = false;
			}
		}
	}
}

void solve(int m, int n) {
	int sum = 0;
	int min = -1;
	for (int i = m; i <= n; i++) {
		if (prime[i]) {
			sum += i;
			if (min == -1) {
				min = i;
			}
		}
	}

	if (min == -1) {
		printf("-1\n");
		return;
	}

	printf("%d\n%d\n", sum, min);
	return;
}

int main() {
	int m, n;
	scanf("%d\n%d", &m, &n);

	initPrime();
	findPrime();
	solve(m, n);
	
	return 0;
}