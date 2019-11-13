#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<pair<int, int>> edges[20001];
int dist[20001];
//int path[20001];
bool visited[20001];
const int INF = 1e9;
int main() {
	int V,E,K;
	cin >> V>> E>>K;
	
	int u, v, w;
	for (int i = 1; i <= E; i++) {
		cin >> u >> v >> w;
		edges[u].push_back(make_pair(v, w));
	}

	for (int i = 1; i <= V; i++) {
		dist[i] = INF;
		visited[i] = false;
	}
	dist[K] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, K));
	while (!pq.empty()) {	
		int idx = pq.top().second;
		pq.pop();

		if (!visited[idx]) {
			visited[idx] = true;
			for (int i = 0; i < edges[idx].size(); i++) {
				int next = edges[idx][i].first;
				int nextW = edges[idx][i].second;
				if (!visited[next] && dist[idx] + nextW < dist[next]) {
					dist[next] = dist[idx] + nextW;
					pq.push(make_pair(dist[next], next));
				}
			}
		}
		//시간328ms

		/*
		while (!pq.empty()) {
			int idx;
			do {
				idx = pq.top().second;
				pq.pop();
			} while (!pq.empty() && check[idx]);
			check[idx] = true;
			for (int i = 0; i < edges[idx].size(); i++) {
				int next = edges[idx][i].first;
				int weight = edges[idx][i].second;
				if (!check[next] && dist[idx] + weight < dist[next]) {
					dist[next] = dist[idx] + weight;
					pq.push(make_pair(dist[next], next));
				}


			}
		}
		//시간 316ms
		*/
	}

	for (int i = 1; i <= V; i++) {
		if (dist[i] == 1e9)
			cout << "INF\n";
		else
			cout << dist[i] << "\n";
	}

	return 0;
}