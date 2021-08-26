#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

#define INF 1e9

int n, m;
vector<pair<int, int>> edge[1001];
int dist[1001];
bool check[1001];

void dijkstra(int start) {
	for(int i=1;i<=n;i++){
		dist[i] = INF;
		check[i] = false;
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, start));
	dist[start] = 0;
	while (!pq.empty()) {
		int v;
		do {
			v = pq.top().second;
			pq.pop();
		} while (!pq.empty() && check[v]);
		check[v] = true;
		for (int i = 0; i < edge[v].size(); i++) {
			int next = edge[v][i].first;
			int d = edge[v][i].second;
			if (!check[next] && dist[next] > dist[v] + d) {
				dist[next] = dist[v] + d;
				pq.push(make_pair(dist[next], next));
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		edge[a].push_back(make_pair(b, c));
	}
	int s, e;
	scanf("%d %d", &s, &e);
	dijkstra(s);
	printf("%d", dist[e]);
	return 0;
}

//다익스트라 알고리즘