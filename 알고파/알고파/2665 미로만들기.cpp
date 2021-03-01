#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <queue>

using namespace std;

bool arr[51][51];
int check[51][51];
queue<pair<int, int>> q;

int main() {
	int n;
	scanf("%d\n", &n);

	for (int i = 1; i <= n; i++) {
		char c;
		for (int j = 1; j <= n; j++) {
			scanf("%c", &c);

			if (c == '0') {
				arr[i][j] = false;
			}
			else {
				arr[i][j] = true;
			}

			check[i][j] = -1;
		}
		scanf("%c", &c);
	}

	check[1][1] = 0;
	q.push(make_pair(1, 1));

	while (!q.empty()) {
		pair<int,int> p = q.front();
		q.pop();
		//printf("%d %d : %d\n", p.first, p.second, check[p.first][p.second]);

		if (p.first + 1 <= n) {
			if (check[p.first + 1][p.second] == -1) {
				check[p.first + 1][p.second] = check[p.first][p.second];
				if (arr[p.first + 1][p.second] == false)
					check[p.first + 1][p.second]++;
				q.push(make_pair(p.first + 1, p.second));
			}
			else {
				if (arr[p.first + 1][p.second]) {
					if (check[p.first + 1][p.second] > check[p.first][p.second]) {
						check[p.first + 1][p.second] = check[p.first][p.second];
						q.push(make_pair(p.first + 1, p.second));
					}
				}
				else {
					if (check[p.first + 1][p.second] > check[p.first][p.second] + 1) {
						check[p.first + 1][p.second] = check[p.first][p.second]+1;
						q.push(make_pair(p.first + 1, p.second));
					}
				}
			}
		}
		if (p.second + 1 <= n) {
			if (check[p.first][p.second+1] == -1) {
				check[p.first][p.second+1] = check[p.first][p.second];
				if (arr[p.first][p.second+1] == false)
					check[p.first][p.second+1]++;
				q.push(make_pair(p.first, p.second+1));
			}
			else {
				if (arr[p.first][p.second+1]) {
					if (check[p.first][p.second+1] > check[p.first][p.second]) {
						check[p.first][p.second+1] = check[p.first][p.second];
						q.push(make_pair(p.first, p.second+1));
					}
				}
				else {
					if (check[p.first][p.second+1] > check[p.first][p.second] + 1) {
						check[p.first][p.second+1] = check[p.first][p.second] + 1;
						q.push(make_pair(p.first, p.second+1));
					}
				}
			}
		}
		if (p.first - 1 > 0) {
			if (check[p.first -1][p.second] == -1) {
				check[p.first - 1][p.second] = check[p.first][p.second];
				if (arr[p.first - 1][p.second] == false)
					check[p.first - 1][p.second]++;
				q.push(make_pair(p.first - 1, p.second));
			}
			else {
				if (arr[p.first - 1][p.second]) {
					if (check[p.first - 1][p.second] > check[p.first][p.second]) {
						check[p.first - 1][p.second] = check[p.first][p.second];
						q.push(make_pair(p.first - 1, p.second));
					}
				}
				else {
					if (check[p.first - 1][p.second] > check[p.first][p.second] + 1) {
						check[p.first - 1][p.second] = check[p.first][p.second] + 1;
						q.push(make_pair(p.first - 1, p.second));
					}
				}
			}
		}
		if (p.second - 1 > 0) {
			if (check[p.first][p.second-1] == -1) {
				check[p.first][p.second-1] = check[p.first][p.second];
				if (arr[p.first][p.second-1] == false)
					check[p.first][p.second-1]++;
				q.push(make_pair(p.first, p.second-1));
			}
			else {
				if (arr[p.first][p.second-1]) {
					if (check[p.first][p.second-1] > check[p.first][p.second]) {
						check[p.first][p.second-1] = check[p.first][p.second];
						q.push(make_pair(p.first, p.second-1));
					}
				}
				else {
					if (check[p.first][p.second-1] > check[p.first][p.second] + 1) {
						check[p.first][p.second-1] = check[p.first][p.second] + 1;
						q.push(make_pair(p.first, p.second-1));
					}
				}
			}
		}
	}

	/*
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", check[i][j]);
		}
		printf("\n");
	}*/

	printf("%d", check[n][n]);

	return 0;
}