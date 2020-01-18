#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#define INF 1e9

using namespace std;

int dist[1000];
bool stone[35][35];
bool ghost[35][35];

struct edge {
	int from, to, cost;
};

edge e[5000];

int mx[] = { -1,0,0,1 };
int my[] = { 0,-1,1,0 };

int main() {
	while (1) {
		int W, H;
		scanf("%d%d", &W, &H);

		if (W == 0 && H == 0)
			break;

		for (int i = 0; i < 35; i++) {
			for (int j = 0; j < 35; j++) {
				stone[i][j] = false;
				ghost[i][j] = false;
			}
		}

		for (int i = 0; i < W*H; i++) {
			dist[i] = INF;
		}

		dist[0] = 0;

		int G;
		scanf("%d", &G);
		for (int i = 0; i < G; i++) {
			int X, Y;
			scanf("%d%d", &Y, &X);
			stone[X][Y] = true;
		}

		int idx = 0;

		int E;
		scanf("%d", &E);
		for (int i = 0; i < E; i++) {
			int X1, Y1, X2, Y2, T;
			scanf("%d%d%d%d%d", &Y1, &X1, &Y2, &X2, &T);
			e[idx].from = X1 * W + Y1;
			e[idx].to = X2 * W + Y2;
			e[idx].cost = T;
			idx++;
			ghost[X1][Y1] = true;
		}

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				int x = i;
				int y = j;

				if (stone[x][y] || ghost[x][y] || (x == H - 1 && y == W - 1))
					continue;

				for (int k = 0; k < 4; k++) {
					int tx = x + mx[k];
					int ty = y + my[k];

					if (tx < 0 || ty < 0 || tx >= H || ty >= W)
						continue;

					if (stone[tx][ty])
						continue;

					e[idx].from = x * W + y;
					e[idx].to = tx * W + ty;
					e[idx].cost = 1;
					idx++;
				}
			}
		}

		bool isCycle = false;
		for (int i = 0; i <= W * H - G - 1; i++) {
			for (int j = 0; j < idx; j++) {
				if (dist[e[j].from] != INF && (dist[e[j].to] > dist[e[j].from] + e[j].cost)) {
					dist[e[j].to] = dist[e[j].from] + e[j].cost;

					if (i == W * H - G - 1) {
						isCycle = true;
						break;
					}
				}
			}
		}




		if (isCycle) {
			printf("Never\n");
		}
		else if (dist[W*H - 1] == INF) {
			printf("Impossible\n");
		}
		else {
			printf("%d\n", dist[W*H - 1]);
		}

	}

	return 0;
}

//3860
//벨만포드
//dfs,bfs?->간선만들기?

/*
입구: (0,0)
출구: (W-1, H-1)
*/