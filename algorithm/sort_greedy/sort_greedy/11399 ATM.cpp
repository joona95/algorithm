#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n;
	int arr[1005];

	cin >> n;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		arr[i] = p;
	}

	sort(arr, arr + n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i] * (n - i);
	}

	cout << sum;

	return 0;
}