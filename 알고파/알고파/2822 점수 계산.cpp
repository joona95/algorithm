#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
	vector<pair<int, int>> v;
	for (int i = 0; i < 8; i++) {
		int c;
		scanf("%d", &c);
		v.push_back(make_pair(c, i+1));
	}

	sort(v.begin(), v.end(), greater<>());

	int sum = 0;
	vector<int> problem;
	for (int i = 0; i < 5; i++) {
		sum += v[i].first;
		problem.push_back(v[i].second);
	}
	sort(problem.begin(), problem.end());
	
	printf("%d\n", sum);
	for (int i = 0; i < 5; i++) {
		printf("%d ", problem[i]);
	}

	return 0;
}