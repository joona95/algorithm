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
integer�� Į�θ� c �������� dp��������
float�� ���� p �������� �ϴ� ��� �Ҽ��� ��°�ڸ������̹Ƿ� *100 ���༭ dp����
*/

/*
while���� 5000�� �����ϹǷ�
while �ȿ� for�� 1�� ������
���� for�� ���� 5000*5000*5000���� 125,000,000,000 => 3�ʾȿ� �Ұ�
3�� = 3�� = 300,000,000

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
