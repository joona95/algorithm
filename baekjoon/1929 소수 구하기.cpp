#include <iostream>
using namespace std;
int main() {
	int m, n;
	cin >> m >> n;
	for (int i = m; i <= n; i++) {
		bool b = false;
		for (long long int j = 2; j * j <= i; j++) {
			//�ð����⵵ ���� : �� ���� �����ٱ����� ������� ��
			//long long int ��� j*j ���� �����÷ο� �߻� ����
			if (i % j == 0) {
				b = true;
				break;
			}
		}
		if (i != 1 && b == false) {
			cout << i << "\n";
		}
	}

	return 0;
}

