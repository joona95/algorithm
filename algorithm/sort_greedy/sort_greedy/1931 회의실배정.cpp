#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//두번째꺼로 오름차순, 두번째꺼 같으면 첫번째꺼로 오름차순
bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else {
		return a.second < b.second;
	}
}

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> t;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		t.push_back(make_pair(a, b));
	}

	//시작시간순
	//길이짧은순
	//끝나는시간순 O

	sort(t.begin(), t.end(), cmp);

	int cnt = 1;
	int e;
	e = t[0].second;
	for (int i = 1; i < n; i++) {
		if (e <= t[i].first) {
			e = t[i].second;
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}


