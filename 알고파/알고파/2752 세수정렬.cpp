#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> v;
	for (int i = 0; i < 3; i++) {
		int c;
		scanf("%d", &c);
		v.push_back(c);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < 3; i++) {
		printf("%d ", v[i]);
	}

	return 0;
}