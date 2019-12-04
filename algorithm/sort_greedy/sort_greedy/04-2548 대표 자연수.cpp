#include <iostream>
using namespace std;
int arr[20005];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int ans = 1e9;
	int min = 1e9;
	for (int i = 0; i < n; i++) {
		int x = arr[i];
		int total = 0;
		for (int j = 0; j < n; j++) {
			total += abs(arr[j] - x);
		}

		if (min > total) {
			min = total;
			ans = x;
		}
		else if (min == total && ans>x) {
			ans = x;
		}
	}

	cout << ans;

	return 0;
}