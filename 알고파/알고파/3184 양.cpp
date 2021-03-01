#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <queue>

using namespace std;

char arr[251][251];
bool check[251][251];

int main() {
	int r, c;
	scanf("%d %d\n", &r, &c);

	for (int i = 1; i <= r; i++) {
		char ch;
		for (int j = 1; j <= c; j++) {
			scanf("%c", &arr[i][j]);
			check[i][j] = false;
		}
		scanf("%c", &ch);
	}

	int oans = 0;
	int vans = 0;

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (arr[i][j] != '#'&&!check[i][j]) {
				int ocnt = 0, vcnt = 0;

				queue<pair<int, int>> q;
				q.push(make_pair(i, j));
				while (!q.empty()) {
					pair<int, int> p = q.front();
					q.pop();
					check[p.first][p.second] = true;
					if (arr[p.first][p.second] == 'o')
						ocnt++;
					else if (arr[p.first][p.second] == 'v')
						vcnt++;

					if (p.first + 1 <= r && arr[p.first + 1][p.second]!='#' && !check[p.first + 1][p.second]) {
						q.push(make_pair(p.first + 1, p.second));
						check[p.first + 1][p.second] = true;
				
					}
					if (p.second + 1 <= c && arr[p.first][p.second + 1]!='#' && !check[p.first][p.second + 1]) {
						q.push(make_pair(p.first, p.second + 1));
						check[p.first][p.second + 1] = true;
						
					}
					if (p.first - 1 > 0 && arr[p.first - 1][p.second]!='#' && !check[p.first - 1][p.second]) {
						q.push(make_pair(p.first - 1, p.second));
						check[p.first - 1][p.second] = true;
						
					}
					if (p.second - 1 > 0 && arr[p.first][p.second - 1]!='#' && !check[p.first][p.second - 1]) {
						q.push(make_pair(p.first, p.second - 1));
						check[p.first][p.second-1] = true;
						
					}
				}

				if (ocnt > vcnt) {
					oans += ocnt;
				}
				else {
					vans += vcnt;
				}
			}
		}
	}
	

	printf("%d %d", oans, vans);

	return 0;
}