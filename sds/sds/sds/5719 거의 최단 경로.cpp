#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <queue>
#include <functional>

using namespace std;


int n, m, s, d;
vector<pair<int, int>> vec[505];
vector<int> trace[505];
//bool visit[505];
int dist[505];

void dijkstra() {
	for (int i = 0; i < n; i++) {
		dist[i] = 1e9;
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, s));
	dist[s] = 0;

	while (!pq.empty()) {
		int v1 = pq.top().second;
		int c = pq.top().first;
		pq.pop();

		for (int i = 0; i < vec[v1].size(); i++) {
			int v2 = vec[v1][i].first;
			int d = vec[v1][i].second;

			if (d == -1) {
				continue;
			}

			if (dist[v2] > dist[v1] + d) {
				dist[v2] = dist[v1] + d;
				pq.push(make_pair(dist[v2], v2));
				trace[v2].clear();
				trace[v2].push_back(v1);
			}
			else if (dist[v2] == dist[v1] + d) {
				trace[v2].push_back(v1);
			}
		}
	}

	
	
}


void BFS(){
	queue<int> q;
	q.push(d);

	while (!q.empty()) {
		int v1 = q.front();
		q.pop();

		for (int i = 0; i < trace[v1].size(); i++) {
			int v2 = trace[v1][i];

			for (int j = 0; j < vec[v2].size(); j++) {
				if (vec[v2][j].first == v1) {
					vec[v2][j].second = -1;
				}
			}
			q.push(v2);
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);

	while (!(n == 0 && m == 0)) {
		scanf("%d%d", &s, &d);


		for (int i = 0; i < m; i++) {
			int u, v, p;
			scanf("%d%d%d", &u, &v, &p);

			vec[u].push_back(make_pair(v, p));
		}

		

		//최단경로계산-다익스트라
		dijkstra();
		/*
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j < vec[i].size(); j++) {
				printf("%d %d,", vec[i][j].first, vec[i][j].second);
			}
			printf("\n");
		}
		printf("****\n");
		*/
		//모든최단경로삭제-bfs
		BFS();

		//거의 최단경로 출력-다익스트라
		dijkstra();
		/*
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j < vec[i].size(); j++) {
				printf("%d %d,", vec[i][j].first,vec[i][j].second);
			}
			printf("\n");
		}*/
		
		
		if (dist[d] >= 1e9) {
			printf("-1\n");
		}
		else {
			printf("%d\n", dist[d]);
		}


		for (int i = 0; i < n; i++) {
			vec[i].clear();
			trace[i].clear();
		}

		scanf("%d%d", &n, &m);

	}



	return 0;
}

//5719