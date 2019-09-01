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
시간초과 : 일일이 2의 개수 5의 개수 다 구하는건 시간초과됨. 2000000000까지이므로
nCr : (n의 2,5 개수) - (n-m의 2,5 개수) - (m의 2,5 개수)
i*=2, i*=5의 범위가 i<=? 조건 비교할때 int 범위 벗어나는 경우 발생하므로 long long int
*/