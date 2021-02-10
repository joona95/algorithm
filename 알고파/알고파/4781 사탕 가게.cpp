#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

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



	}

	return 0;
}

/*
integer인 칼로리 c 기준으로 dp하지말고
float인 가격 p 기준으로 하는 대신 소숫점 둘째자리까지이므로 *100 해줘서 dp해줌
*/

/*
while문도 5000번 가능하므로
while 안에 for문 1번 들어가야함
이중 for문 쓰면 5000*5000*5000으로 125,000,000,000 => 3초안에 불가
3초 = 3억 = 300,000,000

float dp[5001][5001];
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

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 5000; j++) {
				dp[i][j] = 0;
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 5000; j++) {
				int q = j / c[i];
				int r = j % c[i];

				if (dp[i - 1][j] >= q * stof(p[i]) + dp[i - 1][r]) {
					dp[i][j] = dp[i - 1][j];
				}
				else {
					dp[i][j] = q * stof(p[i]) + dp[i - 1][r];
				}
				//cout << "i:" << i << ",j:" << j << "=" << dp[i][j] << "\n";

				if (dp[i][j] > stof(m)) {
					break;
				}
			}
		}

		int answer = 0;
		for (int i = 1; i <= 5000;i++) {
			answer = i;
			if (dp[n][i] >= stof(m)) {
				break;
			}
		}

		cout << answer<<"\n";
	}

	return 0;
}
*/
