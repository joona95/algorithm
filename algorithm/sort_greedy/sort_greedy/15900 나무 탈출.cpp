#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> v[500001];
bool visit[500001];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}
/*
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			printf("%d ", v[i][j]);
		}
		printf("\n");
	}
	*/

	stack<pair<int, int>> s;
	s.push(make_pair(1, 0));
	visit[1] = true;

	int total = 0;
	while (!s.empty()) {
		int x = s.top().first;
		int cnt = s.top().second;
		s.pop();
		//printf("%d %d\n", x, cnt);

		int num = 0;
		for (int i = 0; i < v[x].size(); i++) {
			if (visit[v[x][i]] == false) {
				s.push(make_pair(v[x][i], cnt + 1));
				visit[v[x][i]] = true;
				num++;
			}
		}
		//cout << "num:" << num << "\n";

		if (num == 0) {
			total += cnt;
		}
	}

	//cout << "total:"<<total;

	if (total % 2 == 0) {
		cout << "No";
	}
	else {
		cout << "Yes";
	}

	return 0;
}