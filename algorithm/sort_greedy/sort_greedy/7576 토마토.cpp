#include <iostream>
#include <queue>
using namespace std;

int arr[1005][1005];
queue<pair<pair<int, int>,int>> q;
int main() {
	int m, n;
	cin >> m >> n;

	for (int i = 1; i <= n; i++) {
		int j;
		for (j = 1; j <= m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				q.push(make_pair(make_pair(i, j),0));
			}
		}
	}

	int cnt;
	while (!q.empty()) {
		pair<pair<int,int>,int> idx = q.front();
		cnt = idx.second;
		q.pop();

		if (idx.first.first+1<=n&&arr[idx.first.first+1][idx.first.second] == 0) {
			arr[idx.first.first+1][idx.first.second] = 1;
			q.push(make_pair(make_pair(idx.first.first + 1, idx.first.second),idx.second+1));
		}
		if (idx.first.first-1 >0 && arr[idx.first.first - 1][idx.first.second] == 0) {
			arr[idx.first.first-1][idx.first.second] = 1;
			q.push(make_pair(make_pair(idx.first.first - 1, idx.first.second),idx.second+1));
		}
		if (idx.first.second+1 <= m && arr[idx.first.first][idx.first.second+1] == 0) {
			arr[idx.first.first][idx.first.second+1] = 1;
			q.push(make_pair(make_pair(idx.first.first, idx.first.second + 1),idx.second+1));
		}
		if (idx.first.second-1 >0 && arr[idx.first.first][idx.first.second-1] == 0) {
			arr[idx.first.first][idx.first.second-1] = 1;
			q.push(make_pair(make_pair(idx.first.first, idx.first.second - 1),idx.second+1));
		}

		
	}

	bool complete = true;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] == 0) {
				complete = false;
				break;
			}
		}
	}
	
	if (complete == true)
		cout << cnt;
	else
		cout << "-1";

	return 0;
}