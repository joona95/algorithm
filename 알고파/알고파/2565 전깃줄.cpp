#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int dp[101];

int main() {
	int n;
	scanf("%d", &n);

	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v.push_back(make_pair(a, b));
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		int max = 0;
		for (int j = 0; j < i; j++) {
			if (v[j].second < v[i].second&&max < dp[j]) {
				max = dp[j];
			}
		}
		dp[i] = max + 1;
	}

	int answer = 0;
	for (int i = 0; i < n; i++) {
		if (answer < dp[i]) {
			answer = dp[i];
		}
	}

	answer = v.size() - answer;

	printf("%d", answer);

	return 0;
}

/*
���� �� �����ϴ� �κ� ������ ���� ����!
��ü���� ���� �� �����ϴ� �κ� ������ �� ��ŭ�� ����� ��!
���־� �ϴ� �������� �ּ� ���� �̹Ƿ�!
*/