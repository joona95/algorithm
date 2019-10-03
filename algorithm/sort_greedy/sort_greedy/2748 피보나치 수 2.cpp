#include <iostream>
using namespace std;

long long dp[95]; //최대일때 int범위 넘어가는거 고려하기
int main() {
	int n;
	cin >> n;
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout << dp[n];
	return 0;
}