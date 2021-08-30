#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int v, e;
pair<int, pair<int, int>> edge[100001];

int parents[10001];

int find(int n) {
	if (n == parents[n]) {
		return n;
	}
	return parents[n] = find(parents[n]);
}

void makeUnion(int x, int y) {
	int xParent = find(x);
	int yParent = find(y);
	parents[xParent] = yParent;
}

long long kruskal() {
	long long answer = 0;
	int cnt = 0;
	sort(edge, edge + e);
	for (int i = 0; i < e; i++) {
		int c = edge[i].first;
		int a = edge[i].second.first;
		int b = edge[i].second.second;
		if (find(a) == find(b)) {
			continue;
		}
		makeUnion(a, b);
		answer += c;
		cnt++;
		if (cnt == v - 1) {
			break;
		}
	}
	return answer;
}

int main() {
	scanf("%d %d", &v, &e);
	for (int i = 1; i <= v; i++) {
		parents[i] = i;
	}
	for (int i = 0; i < e; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		edge[i].first = c;
		edge[i].second.first = a;
		edge[i].second.second = b;
	}
	printf("%lld", kruskal());
	return 0;
}

/*
#include <queue>

#define INF 1e9
int dist[10001];
bool check[10001];


long long prim(int start) {
	long long answer = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for(int i=1;i<=v;i++){
		dist[i] = INF;
		check[i] = false;
	}
	pq.push(make_pair(0, start));
	dist[start] = 0;
	while (!pq.empty()) {
		int n;
		do {
			n = pq.top().second;
			pq.pop();
		} while (!pq.empty() && check[n]);
		if (check[n]) {
			break;
		}
		check[n] = true;
		answer += dist[n];
		for (int i = 0; i < edge[n].size(); i++) {
			int next = edge[n][i].first;
			int d = edge[n][i].second;
			if (!check[next] && dist[next] > d) {
				dist[next] = d;
				pq.push(make_pair(d, next));
			}
		}
	}
	return answer;
}

int main() {
	scanf("%d %d", &v, &e);
	for (int i = 0; i < e; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		edge[a].push_back(make_pair(b, c));
		edge[b].push_back(make_pair(a, c));
	}
	printf("%lld", prim(1));
	return 0;
}
*/

/*
크루스칼 : 메모리 2328KB 시간 52ms
프림 : 메모리 4584KB 시간 60ms

프림 알고리즘은 꼭지점(정점)을 선택하고 그것과 연결된 가장 적은 비용의 정점을 선택하는 방식이다. 
크루스칼 알고리즘은 모든 비용을 순차적으로 나열하여 가장 적은 비용이 드는 간선(신장)들을 선택해 나가는 방식이다.
*/