#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

using namespace std;

int m[101];
int c[101];
int dp[101][10001];

int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &m[i]);
	}
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &c[i]);
		sum += c[i];
	}

	
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= sum; j++) {
			if (j < c[i]) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				if (dp[i - 1][j] >= dp[i - 1][j - c[i]] + m[i]) {
					dp[i][j] = dp[i - 1][j];
				}
				else {
					dp[i][j] = dp[i - 1][j - c[i]] + m[i];
				}
			}
		}
	}

	int answer;
	for (int i = 0; i <= sum; i++) {
		if (dp[N][i] >= M) {
			answer = i;
			break;
		}
	}

	printf("%d", answer);

	return 0;
}

/*
비용 대비 최대로 얻을 수 있는 메모리 구하기
*/