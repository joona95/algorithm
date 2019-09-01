#include <iostream>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	
	int arr[2] = { 0, };
	for (long long int i = 2; i <= n; i *= 2) {
		arr[0] += n / i;
	}
	for (long long int i = 5; i <= n; i *= 5) {
		arr[1] += n / i;
	}

	for (long long int i = 2; i <= n-m; i *= 2) {
		arr[0] -= ((n-m) / i);
	}
	for (long long int i = 5; i <= n-m; i *= 5) {
		arr[1] -= ((n-m) / i);
	}

	for (long long int i = 2; i <= m; i *= 2) {
		arr[0] -= (m / i);
	}
	for (long long int i = 5; i <= m; i *= 5) {
		arr[1] -= (m / i);
	}

	if (arr[0] < arr[1])
		cout << arr[0];
	else
		cout << arr[1];

	return 0;
}

/*
�ð��ʰ� : ������ 2�� ���� 5�� ���� �� ���ϴ°� �ð��ʰ���. 2000000000�����̹Ƿ�
nCr : (n�� 2,5 ����) - (n-m�� 2,5 ����) - (m�� 2,5 ����)
i*=2, i*=5�� ������ i<=? ���� ���Ҷ� int ���� ����� ��� �߻��ϹǷ� long long int
*/