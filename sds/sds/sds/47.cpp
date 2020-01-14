#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

vector<pair<int, int>> vec[1005];
vector<int> erases[1005];
int dist[1005];
bool visit[1005];

int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);

	for (int i = 1; i <= n; i++) {
		dist[i] = 1e9;
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);

		vec[a].push_back(make_pair(b, c));
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, 1));
	dist[1] = 0;

	while (!pq.empty()) {
		int c, v;
		do {
			c = pq.top().first;
			v = pq.top().second;
			visit[v] = true;
			pq.pop();
		} while (!pq.empty() && visit[v]);

		for (int i = 0; i < vec[v].size(); i++) {
			int u = vec[v][i].first;
			int d = vec[v][i].second;
			if (dist[u] > dist[v] + d) {
				dist[u] = dist[v] + d;
				pq.push(make_pair(dist[u], u));
			}
		}
	}
	


	for (int i = 1; i <= n; i++) {
		printf("%d ", dist[i]);
	}

	return 0;
}

//1854