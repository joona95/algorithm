#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <queue>

using namespace std;

bool arr[101][101];
bool check[101][101];
queue<pair<pair<int, int>, int>> q;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char c;
			scanf("%c", &c);

			if (c == '0') {
				arr[i][j] = 0;
			}
			else {
				arr[i][j] = 1;
			}
		}
	}

	q.push(make_pair(make_pair(1, 1), 1));

	int cnt;
	while (!q.empty()) {
		pair<int, int> p = q.front().first;
		cnt = q.front().second;
		q.pop();

		if (p.first == n && p.second == m)
			break;

		if (p.first - 1 > 0 && arr[p.first - 1][p.second] && !check[p.first - 1][p.second]) {
			q.push(make_pair(make_pair(p.first - 1, p.second), cnt + 1));
		}
		if (p.second - 1 > 0 && arr[p.first][p.second-1] && !check[p.first][p.second-1]) {
			q.push(make_pair(make_pair(p.first, p.second-1), cnt + 1));
		}
		if (p.first + 1 <=n && arr[p.first + 1][p.second] && !check[p.first + 1][p.second]) {
			q.push(make_pair(make_pair(p.first + 1, p.second), cnt + 1));
		}
		if (p.second + 1 <= m && arr[p.first][p.second + 1] && !check[p.first][p.second + 1]) {
			q.push(make_pair(make_pair(p.first, p.second + 1), cnt + 1));
		}
	}

	printf("%d", cnt);

	return 0;
}
