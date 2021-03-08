#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int m, n, k;
int num[51][51];
bool check[51][51];

void bfs(int a, int b) {
	queue<pair<int,int>> q;
	
	q.push(make_pair(a, b));

	while (!q.empty()) {
		pair<int,int> front = q.front();
		q.pop();
		check[front.first][front.second] = true;

		if (front.first + 1<n && num[front.first + 1][front.second] == 1) {
			if (!check[front.first + 1][front.second]) {
				q.push(make_pair(front.first + 1, front.second));
				check[front.first + 1][front.second] = true;
			}
		}
		if (front.second+1< m && num[front.first][front.second+1] == 1) {
			if (!check[front.first][front.second+1]) {
				q.push(make_pair(front.first, front.second+1));
				check[front.first][front.second+1] = true;
			}
		}
		if (0<=front.first - 1&& num[front.first - 1][front.second] == 1) {
			if (!check[front.first - 1][front.second]) {
				q.push(make_pair(front.first - 1, front.second));
				check[front.first - 1][front.second] = true;
			}
		}
		if (0<=front.second - 1&& num[front.first][front.second - 1] == 1) {
			if (!check[front.first][front.second - 1]) {
				q.push(make_pair(front.first, front.second - 1));
				check[front.first][front.second - 1] = true;
			}
		}
	}
}

int main() {
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		
		scanf("%d %d %d", &m, &n, &k);

		for (int a = 0; a < n; a++) {
			for (int b = 0; b < m; b++) {
				num[a][b] = 0;
				check[a][b] = false;
			}
		}

		for (int j = 0; j < k; j++) {
			int x, y;
			scanf("%d %d", &x, &y);//x <m , y<n

			num[y][x] = 1;
		}

		int answer = 0;
		for (int a = 0; a < n; a++) {
			for (int b = 0; b < m; b++) {
				if (!check[a][b]&&num[a][b]==1) {
					bfs(a, b);
					answer++;
				}
			}
		}
		
		printf("%d\n", answer);
	}

	return 0;
}

//x= 가로 , y= 세로!!