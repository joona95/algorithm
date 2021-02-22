#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <queue>
#define INF 1e9

using namespace std;

vector<int> v[300001];
bool check[300001];
int dist[300001];

int main() {
	int n, m, k, x;
	scanf("%d %d %d %d", &n, &m, &k, &x);

	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
	}

	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
		check[i] = false;
	}

	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push(make_pair(0,x));
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
			int next = v[idx][i];
			if (!check[next] && dist[next] > dist[idx] + 1) {
				dist[next] = dist[idx] + 1;
				pq.push(make_pair(dist[next], next));
			}
		}
	}

	bool find = false;
	for (int i = 1; i <= n; i++) {
		if (dist[i] == k) {
			find = true;
			printf("%d\n", i);
		}
	}

	if (find == false) {
		printf("-1\n");
	}

	return 0;
}