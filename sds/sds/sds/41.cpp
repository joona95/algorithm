#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <functional>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int,int>> vec[20005];
int cost[20005];
bool visit[20005];

int main() {
	int v, e,k;
	scanf("%d%d%d", &v, &e,&k);

	for (int i = 1; i <= v; i++) {
		cost[i] = 1e9;
		visit[i] = false;
	}

	for (int i = 0; i < e; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);

		vec[u].push_back(make_pair(v,w));
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, k));
	cost[k] = 0;
	//visit[k] = true;
	

	while (!pq.empty()) {
		int c, u;
		do {
			c = pq.top().first;
			u = pq.top().second;
			pq.pop();
		} while (!pq.empty() && visit[u] == true); //****이미 지나간거는 빼기
		visit[u] = true;	
		//printf("\n%d %d\n", c, u);

		for (int i = 0; i < vec[u].size(); i++) {
			int v = vec[u][i].first;
			int w = vec[u][i].second;
			if (visit[v] == false) {
				if (cost[v] > c + w) {
					cost[v] = c + w;
					pq.push(make_pair(c + w, v));
				}		
			}
		}
	}

	for (int i = 1; i <= v; i++) {
		if (cost[i] < 1e9)
			printf("%d\n", cost[i]);
		else
			printf("INF\n");
	}

	return 0;
}

/*
0 1
2 2, 3 3
3 3, 6 3, 7 4
6 3, 7 4, 9 4
7 4, 9 4, 
*/