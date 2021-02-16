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
	f[n] = 100000001;

	long long answer = 0;
	for (int i = 0; i < n - 1; i++) {
		int s = i, e = n;

		while (s < e) {
			int mid = (s + e) / 2;

			if (f[i] >= 0.9 * f[mid]) {
				s = mid + 1;

			}
			else {
				e = mid;

			}
		}

		answer += e - 1 - i;
	}

	printf("%lld\n", answer);

	return 0;
}

/*
���� long long �ڷ���
upper bound ����
>= ���� �� �ε��Ҽ��� f ���̸� Ʋ�ȴٰ� ���. �ε��Ҽ��� �񱳰� ����� �ȵǳ���.
*/