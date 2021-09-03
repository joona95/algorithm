#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

using namespace std;

int n;
int answer = 0;
char candy[51][51];
int mx[4] = { 0, 0, -1, 1 };
int my[4] = { -1, 1, 0, 0 };

void change(int i, int j, int x, int y) {
	char tmp = candy[i][j];
	candy[i][j] = candy[x][y];
	candy[x][y] = tmp;
}

void findCandyCount() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int m = 1; m < 3; m++) {
				int prex = i;
				int prey = j;
				int x = i + mx[m];
				int y = j + my[m];
				int cnt = 1;
				while (0 <= x && x < n && 0 <= y && y < n) {
					if (candy[prex][prey] != candy[x][y]) {
						break;
					}
					cnt++;
					prex = x;
					prey = y;
					x = x + mx[m];
					y = y + my[m];
				}
				if (answer < cnt) {
					answer = cnt;
				}
			}
		}
	}
}

void solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int m = 0; m < 4; m++) {
				int x = i + mx[m];
				int y = j + my[m];
				if (0 <= x && x < n && 0 <= y && y < n && candy[i][j]!=candy[x][y]) {
					change(i, j, x, y);
					findCandyCount();
					change(i, j, x, y);
				}
			}
		}
	}
}

int main() {
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n+1; j++) {
			scanf("%c", &candy[i][j]);
		}
	}
	solve();
	printf("%d", answer);
	return 0;
}

/*
prex = x;
prey = y;
x = x + mx[m];
y = y + my[m];
이부분에서 처음에 i, j 에 x, y를 넣어줘서 for문 돌 때 문제가 생겼었음.
지금 findCandyCount 에서 상하좌우 다 검사하고 있는데 상하 둘 다 할 필요 없이 하나만, 좌우 둘 다 할 필요 없이 하나만 하니까
2배로 속도가 줄었음.
더 최적화할 수 있을 것 같음. 지금도 중복 검사하고 있는 게 꽤 있음.
*/