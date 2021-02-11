#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

/*
int dp[10001];
int c[5001];
string p[5001];

int main() {
	while (1) {
		int n;
		string m;
		cin >> n >> m;

		if (n == 0 && m == "0.00") {
			break;
		}

		for (int i = 1; i <= n; i++) {
			cin >> c[i] >> p[i];
		}

		int money = stof(m) * 100;

		for (int i = 1; i <= money; i++) {
			dp[i] = 0;
		}

		for (int i = 1; i <= n; i++) {
			int price = stof(p[i]) * 100;
			for (int j = price; j <= money; j++) {
				if (dp[j] < dp[j - price] + c[i]) {
					dp[j] = dp[j - price] + c[i];
				}
			}
		}

		cout << dp[money] << "\n";

	}

	return 0;
}


integer인 칼로리 c 기준으로 dp하지말고
float인 가격 p 기준으로 하는 대신 소숫점 둘째자리까지이므로 *100 해줘서 dp해줌
*/

/*
시간초과=> stof를 이중 for문 안에 넣어두니까 시간초과가 난 거였음.
칼로리 기준 dp의 경우 X
사탕 나눠서 살 수 없어서 
*/



