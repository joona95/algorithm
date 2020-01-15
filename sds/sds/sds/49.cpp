#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int mx[] = { -1,0,0,1 };
int my[] = { 0,-1,1,0 };

vector<pair<int, int>> vec[35][35];
bool map[35][35];
int dist[35][35];
int X, H, G, X, Y, E;

int main() {

	while (1) {

		scanf("%d%d", &W, &H);
		if (W == 0 && H == 0)
			break;
		scanf("%d", &G);

		for (int i = 0; i < G; i++) {
			scanf("%d%d", &X, &Y);

			map[Y][X] = true; //묘비 표시
		}


		//간선 연결
		queue<pair<int, int>> q;
		q.push(make_pair(0, 0));

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int tx = x + mx[i];
				int ty = y + my[i];

				if (0 <= tx&&tx < W && 0 <= ty&&ty < H) {
					if (!map[Y][X])
						
				}
			}
		}


		scanf("%d", &E);
		for (int i = 0; i < E; i++) {
			int X1, Y1, X2, Y2, T;
			scanf("%d%d%d%d%d", &X1, &Y1, &X2, &Y2, &T);

			//귀신구멍 간선연결

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