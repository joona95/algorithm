#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int n, m, x;
vector<pair<int, int>> v[1005];
vector<pair<int, int>> v2[1005];
int dist[1005];
int dist2[1005];
//int path[1005];
bool check[1005];

int min(int a, int b) {
	if (a > b)
		return b;
	else
		return a;
}

void dijkstra(int r) {
	for (int i = 1; i <= n; i++)
		dist[i] = 1e9;
	memset(check, false, sizeof(check));
	//memset(path, -1, sizeof(path));

	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, r));
	dist[r] = 0;
	while (!pq.empty()) {
		int d = pq.top().first;
		int node = pq.top().second;
		check[node] = true;
		pq.pop();

		for (int i = 0; i < v[node].size(); i++) {
			if (check[v[node][i].first] == false) {
				pq.push(make_pair(min(dist[v[node][i].first], d + v[node][i].second), v[node][i].first));
				dist[v[node][i].first] = min(dist[v[node][i].first], d + v[node][i].second);
			}
		}
	}



	for (int i = 1; i <= n; i++)
		dist2[i] = 1e9;
	memset(check, false, sizeof(check));
	//memset(path, -1, sizeof(path));

	pq.push(make_pair(0, r));
	dist2[r] = 0;
	while (!pq.empty()) {
		int d = pq.top().first;
		int node = pq.top().second;
		check[node] = true;
		pq.pop();

		for (int i = 0; i < v2[node].size(); i++) {
			if (check[v2[node][i].first] == false) {
				pq.push(make_pair(min(dist2[v2[node][i].first], d + v2[node][i].second), v2[node][i].first));
				dist2[v2[node][i].first] = min(dist2[v2[node][i].first], d + v2[node][i].second);
			}
		}
	}
}

int main() {	
	cin >> n >> m >> x;
	for (int i = 1; i <= m; i++) {
		int s, e, t;
		cin >> s >> e >> t;
		v[s].push_back(make_pair(e, t));
		v2[e].push_back(make_pair(s, t));
	}
	
	
	dijkstra(x);

	/*
	for (int i = 1; i <= n; i++) {
		cout << dist[i] << " ";
	}
	cout << "\n";
	for (int i = 1; i <= n; i++) {
		cout << dist2[i] << " ";
	}
	cout << "\n";
	*/

	int max = 0;
	for (int i = 1; i <= n; i++) {
		if (max < dist[i]+dist2[i]) {
			max = dist[i]+dist2[i];
		}
	}

	cout << max;

	return 0;
}

//시간초과
/*dijkstra 목적지 시작점으로 한번, 역방향 그래프로 목적지에서 한번 하면
for을 n번 돌리지 않아도 dijkstra 두번만에 가능.
*/