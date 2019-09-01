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
	//소인수: 약수 중 소수인 약수. 
	//1은 소수가 아니라서 1일때 1을 출력하는게 아니라 아무것도 출력하지 않아야 함.

	return 0;
}