#include <iostream>
using namespace std;
/*
int main() {
	int n;
	cin >> n;

	int mul = 1;
	for (int i = n; i > 0; i--) {
		mul *= i;
	}
	cout << mul;

	return 0;
}
*/
//메모리 1984kb

int fac(int n) {
	if (n <= 1) {
		return 1;
	}
	else {
		return n* fac(n - 1);
	}
}

int main() {
	int n;
	cin >> n;
	cout << fac(n);
	return 0;
}
//메모리 1988kb