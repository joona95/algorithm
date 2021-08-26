#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;
bool v[1000001];
int main() {
	int k = 0;
	for (int i = 2; i <= 1000000; i++) {
		v[i] = true;
		for (long long int j = 2; j * j <= i; j++) {
			if (i % j == 0) {
				v[i] = false;
				break;
			}
		}
	}

	while (true) {
		int n;
		scanf("%d", &n);
		if (n == 0)
			break;

		bool b = false;
		for (int i = 2; i <= 1000000; i++) {
			if (v[i] && v[n - i]) {
				b = true;
				printf("%d = %d + %d\n", n, i, n-i);
				break;
			}
		}

		if(b==false) {
			printf("Goldbach's conjecture is wrong.\n");
		}
	}

	return 0;
}

//시간초과 문제
//vector 대신 array 선언
//cin, cout 대신 printf, scanf
//소수를 일일이 저장하는게 아니라 1000000까지에서 숫자마다 소수인지 아닌지 bool로 표현가능
