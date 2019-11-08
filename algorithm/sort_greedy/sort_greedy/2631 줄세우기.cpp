#include <iostream>
using namespace std;

int arr[205];
int dp[205];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		int max = 0;
		for (int j = 0; j < i; j++) {
			if (arr[j]<arr[i] && max < dp[j]) {
				max = dp[j];
			}
		}
		dp[i] = max+1;
	}

	int m = 0;
	for (int i = 1; i <= n; i++) {
		if (m < dp[i]) {
			m = dp[i];
		}
	}

	cout << n - m;

	return 0;
}