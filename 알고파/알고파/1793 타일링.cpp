#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <string>
#include <cstring>
#include <vector>

using namespace std;


int main() {
	int n;
	while (scanf("%d", &n)!=EOF) {
		vector<int> dp[251];
		
		dp[0].push_back(1);
		dp[1].push_back(1);
		dp[2].push_back(3);

		for (int i = 3; i <= n; i++) {
			int carry = 0;
			for (int j = 0; j < dp[i - 2].size(); j++) {
				int sum = dp[i - 2][j] * 2 + dp[i - 1][j] + carry;
				if (sum < 10) {
					dp[i].push_back(sum);
					carry = 0;
				}
				else {
					carry = sum / 10;
					sum = sum % 10;
					dp[i].push_back(sum);
					if (j == dp[i - 2].size() - 1) {
						if (dp[i - 1].size() > dp[i - 2].size()) {
							dp[i].push_back(carry + dp[i - 1][j + 1]);
						}
						else {
							dp[i].push_back(carry);
						}
					}
				}
			}
		}

		for (int i = dp[n].size() - 1; i >= 0; i--) {
			printf("%d", dp[n][i]);
		}
		printf("\n");
	}

	return 0;
}

/*
long long���ε� ���� Ŀ���� �ȵż� string ��ȯ �ʿ�
string ��ȯ �ʹ� ����� -> vector<int> �迭�� �ٲ�

�ƹ��͵� ���ϴ� ��쵵 1����
*/