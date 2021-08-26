#include <iostream>
using namespace std;
int main() {
	int m, n;
	cin >> m >> n;
	for (int i = m; i <= n; i++) {
		bool b = false;
		for (long long int j = 2; j * j <= i; j++) {
			//시간복잡도 개선 : 그 수의 제곱근까지만 나누어보는 것
			//long long int 써야 j*j 에서 오버플로우 발생 안함
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

