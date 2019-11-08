#include <iostream>
using namespace std;
int arr[50005];
int sum[50005];
int dp[50005];
int main() {
	int n, m;
	cin >> n;
	//int *arr = new int[n+5];
	//int *sum = new int[n+5];
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		
	}
	cin >> m;


	for (int i = 1; i <= 3*m; i++) {
		dp[i] += arr[i] + dp[i - 1];
	}

	for (int i = m; i <= n; i++) {
		sum[i] = 0;
		for (int s = 0; s < m; s++) {
			sum[i] += arr[i - s];
		}
	}
	
	for (int i = 3*m + 1; i <= n; i++) {
		dp[i] = dp[i - 1];

		int max = 0;
		for (int j = i - m; j>=2*m ; j--) {
			for (int k = j - m; k >=m; k--) {
				if (max < sum[i] + sum[j] + sum[k]) {
					max = sum[i] + sum[j] + sum[k];
				}
			}
		}

		if (max > dp[i]) {
			dp[i] = max;
		}
	}

	
	int max = 0;
	for (int i = 1; i <= n; i++) {
		if (max < dp[i]) {
			max = dp[i];
		}
	}

	cout <<max;

	return 0;
}

/*런타임 에러 왜 나는거지?
한 소형 열차당 끌 수 있는 객차 최대 수
그것보다 작을 수도 있음 고려해야함

그렇지만 계속 런타임 에러가 뜬다.
*/

