#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <queue>
#define INF 1e9

using namespace std;

vector<pair<int,int>> v[1001];
bool check[1001];
int dist[1001];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back(make_pair(b, c));
	}

	int x, y;
	scanf("%d %d", &x, &y);

	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
		check[i] = false;
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, x));
	dist[x] = 0;

	while (!pq.empty()) {
		int idx;
		do {
			idx = pq.top().second;
			pq.pop();
		} while (!pq.empty() && check[idx]);

		if (check[idx])
			break;

		check[idx] = true;

		for (int i = 0; i < v[idx].size(); i++) {
			int next = v[idx][i].first;
			int cost = v[idx][i].second;
			if (!check[next] && dist[next] > dist[idx] + cost) {
				dist[next] = dist[idx] + cost;
				pq.push(make_pair(dist[next], next));
			}
		}
	}

	printf("%d", dist[y]);

	return 0;
}