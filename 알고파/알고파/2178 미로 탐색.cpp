#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <queue>

using namespace std;

bool arr[101][101];
bool check[101][101];
queue<pair<pair<int, int>, int>> q;

int main() {
	int n, m;
	scanf("%d %d\n", &n, &m);

	for (int i = 1; i <= n; i++) {
		char c;
		for (int j = 1; j <= m; j++) {
			scanf("%c", &c);

			if (c == '0') {
				arr[i][j] = false;
			}
			else {
				arr[i][j] = true;
			}
		}
		scanf("%c", &c);
	}

	q.push(make_pair(make_pair(1, 1), 1));

	int cnt;
	while (!q.empty()) {
		pair<int, int> p = q.front().first;
		cnt = q.front().second;
		check[p.first][p.second] = true;
		q.pop();
		
		if (p.first == n && p.second == m)
			break;

		if (p.first + 1 <=n && arr[p.first + 1][p.second] && !check[p.first + 1][p.second]) {
			q.push(make_pair(make_pair(p.first + 1, p.second), cnt + 1));
			check[p.first + 1][p.second] = true;
		}
		if (p.second + 1 <= m && arr[p.first][p.second + 1] && !check[p.first][p.second + 1]) {
			q.push(make_pair(make_pair(p.first, p.second + 1), cnt + 1));
			check[p.first][p.second + 1] = true;
		}
		if (p.first - 1 > 0 && arr[p.first - 1][p.second] && !check[p.first - 1][p.second]) {
			q.push(make_pair(make_pair(p.first - 1, p.second), cnt + 1));
			check[p.first - 1][p.second] = true;
		}
		if (p.second - 1 > 0 && arr[p.first][p.second - 1] && !check[p.first][p.second - 1]) {
			q.push(make_pair(make_pair(p.first, p.second - 1), cnt + 1));
			check[p.first][p.second] = true;
		}
	}

	printf("%d", cnt);

	return 0;
}
