#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;

	int div = 2;
	while (n != 1) {
		if (n % div == 0) {
			n = n / div;
			cout << div << "\n";
		}
		else {
			div++;
		}
	}
	//���μ�: ��� �� �Ҽ��� ���. 
	//1�� �Ҽ��� �ƴ϶� 1�϶� 1�� ����ϴ°� �ƴ϶� �ƹ��͵� ������� �ʾƾ� ��.

	return 0;
}