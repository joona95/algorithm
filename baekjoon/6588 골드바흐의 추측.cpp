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

//�ð��ʰ� ����
//vector ��� array ����
//cin, cout ��� printf, scanf
//�Ҽ��� ������ �����ϴ°� �ƴ϶� 1000000�������� ���ڸ��� �Ҽ����� �ƴ��� bool�� ǥ������
