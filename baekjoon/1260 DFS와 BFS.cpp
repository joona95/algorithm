#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void DFS(int v,int n, bool arr[][1001]) {

	bool result[1001] = { 0, };
	stack<int> s;
	s.push(v);
	bool b = false;
	while (!b && !s.empty()) {
		int r = s.top();
		if (result[r] == true) {
			s.pop();
			continue;
		}
		else
			result[r] = true;
		cout << r << " ";
		s.pop();
		for (int i = n; i > 0; i--) {
			if (arr[r][i]) {
				s.push(i);
				//arr[r][i] = false;
				//arr[i][r] = false;
			}
		}

		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (result[i])
				cnt++;
		}
		if (cnt == n)
			b = true;
	}
}

void BFS(int v,int n, bool arr[][1001]) {
	bool result[1001] = { 0, };
	queue<int> q;
	q.push(v);
	bool b = false;
	while (!b&&!q.empty()) {
		int r = q.front();
		if (result[r] == true) {
			q.pop();
			continue;
		}
		else
			result[r] = true;
		cout << r << " ";
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (arr[r][i]) {
				q.push(i);
				//arr[r][i] = false;
				//arr[i][r] = false;
			}
		}

		int cnt = 0;
		for (int i = 1; i <=n; i++)
		{
			if (result[i])
				cnt++;
		}

		if (cnt == n)
			b = true;
	}

}

bool arr[1001][1001] = { 0, };
int main() {
	int n, m, v;
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		arr[x][y] = true;
		arr[y][x] = true;
	}

/*
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	*/

	
	DFS(v, n, arr);
	cout << "\n";
	BFS(v, n, arr);

	return 0;
}