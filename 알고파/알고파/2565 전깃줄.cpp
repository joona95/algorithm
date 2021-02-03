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
가장 긴 증가하는 부분 수열과 원리 같음!
전체에서 가장 긴 증가하는 부분 수열의 수 만큼을 빼줘야 함!
없애야 하는 전깃줄의 최소 개수 이므로!
*/