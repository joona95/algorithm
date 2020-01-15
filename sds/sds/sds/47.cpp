//2020.01.15
//1854
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

vector<pair<int, int>> vec[1005];
//int cnt[1005];
priority_queue<int> dist[1005];
//bool visit[1005];

int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);

	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);

		vec[a].push_back(make_pair(b, c));
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, 1));
	dist[1].push(0); //*****

	while (!pq.empty()) {
		int c, v;
		c = pq.top().first;
		v = pq.top().second;
		pq.pop();


		for (int i = 0; i < vec[v].size(); i++) {
			int u = vec[v][i].first;
			int d = vec[v][i].second;

			if (dist[u].size() < k) {
				dist[u].push(c + d);
				pq.push(make_pair(c+d, u));
			}
			else if (dist[u].top() > c + d) {
				dist[u].pop();
				dist[u].push(c + d);
				pq.push(make_pair(c + d, u));
			}
		}
	}
	

	
	for (int i = 1; i <= n; i++) {
		if (dist[i].size() != k)
			printf("-1\n");
		else
			printf("%d\n", dist[i].top());
	}

	return 0;
}

