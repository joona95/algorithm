#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <queue>

using namespace std;

int l;
int sx, sy, ex, ey;
bool check[301][301];

int bfs() {
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < l; j++) {
			check[i][j] = false;
		}
	}

	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(sx, sy), 0));

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int c = q.front().second;
		q.pop();
		check[x][y] = true;
		//printf("%d %d %d\n", x, y, c);

		if (x == ex && y == ey) {
			return c;
		}

		if (x - 2 >= 0 && y - 1 >= 0 && !check[x - 2][y - 1]) {
			q.push(make_pair(make_pair(x - 2, y - 1), c + 1));
			check[x - 2][y - 1] = true;
		}
		if (x - 1 >= 0 && y - 2 >= 0 && !check[x - 1][y - 2]) {
			q.push(make_pair(make_pair(x - 1, y - 2), c + 1));
			check[x - 1][y - 2] = true;
		}
		if (x - 2 >= 0 && y + 1 < l && !check[x - 2][y + 1]) {
			q.push(make_pair(make_pair(x - 2, y + 1), c + 1));
			check[x - 2][y + 1] = true;
		}
		if (x - 1 >= 0 && y + 2 < l && !check[x - 1][y + 2]) {
			q.push(make_pair(make_pair(x - 1, y + 2), c + 1));
			check[x - 1][y + 2] = true;
		}
		if (x + 2 < l && y - 1 >= 0 && !check[x + 2][y - 1]) {
			q.push(make_pair(make_pair(x + 2, y - 1), c + 1));
			check[x + 2][y - 1] = true;
		}
		if (x + 1 < l && y - 2 >= 0 && !check[x + 1][y - 2]) {
			q.push(make_pair(make_pair(x + 1, y - 2), c + 1));
			check[x + 1][y - 2] = true;
		}
		if (x + 2 < l && y + 1 < l && !check[x + 2][y + 1]) {
			q.push(make_pair(make_pair(x + 2, y + 1), c + 1));
			check[x + 2][y + 1] = true;
		}
		if (x + 1 <l && y + 2 < l && !check[x + 1][y + 2]) {
			q.push(make_pair(make_pair(x + 1, y + 2), c + 1));
			check[x + 1][y + 2] = true;
		}

	}

}

int main() {
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++) {

		scanf("%d", &l);
		scanf("%d %d", &sx, &sy);
		scanf("%d %d", &ex, &ey);

		int answer = bfs();
		printf("%d\n", answer);
	}

	return 0;
}