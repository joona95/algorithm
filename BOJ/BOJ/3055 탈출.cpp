#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <queue>

using namespace std;

int mx[] = { -1,1,0,0 };
int my[] = { 0,0,-1,1 };
char map[55][55];
bool check[55][55];

int main() {
	int r, c;
	scanf("%d %d\n", &r, &c);

	queue<pair<pair<int, int>,int>> q;
	queue<pair<int, int>> w;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c+1; j++) {
			char c;
			scanf("%c", &c);
			if (c != '\n') {
				map[i][j] = c;
			}
			if (c == 'S') {
				q.push(make_pair(make_pair(i, j),0));
			}
			if (c == '*') {
				w.push(make_pair(i, j));
			}
		}
	}

	int w_cnt = 0;
	while (!q.empty()) {
		int cnt = q.front().second;

		if (cnt == w_cnt) {
			int w_size = w.size();
			for (int j = 0; j < w_size; j++) {
				int y = w.front().first;
				int x = w.front().second;
				w.pop();
				for (int i = 0; i < 4; i++) {

					int ty = y + my[i];
					int tx = x + mx[i];
					if (tx >= 0 && tx < c&&ty >= 0 && ty < r&&map[ty][tx] == '.') {
						w.push(make_pair(ty, tx));
						map[ty][tx] = '*';

					}
				}
			}
			w_cnt++;			
		}


		/*
		printf("--------------\n");
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				printf("%c", map[i][j]);
			}
			printf("\n");
		}
		printf("--------------\n");
		*/

		int y = q.front().first.first;
		int x = q.front().first.second;
		check[y][x] = true;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ty = y + my[i];
			int tx = x + mx[i];
			if (tx >= 0 && tx < c&&ty >= 0 && ty < r&&check[ty][tx]!=true) {
				if (map[ty][tx] == '.') {
					q.push(make_pair(make_pair(ty, tx), cnt + 1));
					check[ty][tx] = true;
				}
				else if (map[ty][tx] == 'D') {
					printf("%d\n", cnt+1);
					return 0;
				}
			}
		}
	}

	printf("KAKTUS\n");
	return 0;
}

//물 초기화 = cnt횟수 같을때 물번지면 안됨
/*
이전에는 arr[55][55], visited[55][55], cnt[55][55]해서
queue는 하나에 물부터 넣고 위치 넣고
*/