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


integer�� Į�θ� c �������� dp��������
float�� ���� p �������� �ϴ� ��� �Ҽ��� ��°�ڸ������̹Ƿ� *100 ���༭ dp����
*/

/*
�ð��ʰ�=> stof�� ���� for�� �ȿ� �־�δϱ� �ð��ʰ��� �� �ſ���.
Į�θ� ���� dp�� ��� X
���� ������ �� �� ��� 
*/



