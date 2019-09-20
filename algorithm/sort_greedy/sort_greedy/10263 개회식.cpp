#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int h;
		cin >> h;
		v.push_back(h);
	}

	sort(v.begin(), v.end());

	int cnt = 0;
	int s = 0;
	for (int i = 0; i < n; i++) {
		//가로 세로 비교?

	}

	cout << cnt;
	
	return 0;
}