#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		int s, t;
		cin >> s >> t;
		v.push_back(make_pair(s, t));
	}

	sort(v.begin(), v.end());

	priority_queue<int, vector<int>, greater<int>> end;
	end.push(v[0].second);
	
	for (int i = 1; i < n; i++) {
		if (end.top() <= v[i].first) {
			end.pop();
		}
		end.push(v[i].second);
	}

	cout << end.size();

	return 0;
}

/*
끝나는시간으로 정렬했을 때 반례:
6
1 3
2 5
4 12
7 8
7 11
9 10
*/