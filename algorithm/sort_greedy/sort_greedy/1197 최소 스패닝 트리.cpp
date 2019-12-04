//Kruskal
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Disjointset {
	vector<int> par;
	Disjointset(int n) {
		par.resize(n + 5, -1);
	}

	int f(int x) {
		if (par[x] == -1)
			return x;
		return par[x] = f(par[x]);
	}

	void u(int x, int y) {
		x = f(x);
		y = f(y);
		if (x == y)
			return;
		par[x] = y;
	}
};

struct Edges {
	int a, b, c;
};

bool cmp(Edges x, Edges y) {
	return x.c < y.c;
}

Edges edge[100005];
int main() {
	int v, e;
	cin >> v >> e;
	for (int i = 1; i <= e; i++) {
		cin >> edge[i].a >> edge[i].b >> edge[i].c;
	}

	sort(edge + 1, edge + e + 1, cmp);

	Disjointset d(v);
	int cnt = 0, idx = 1;
	int total = 0;
	while (cnt < v-1) {
		if (d.f(edge[idx].a) != d.f(edge[idx].b)) {
			d.u(edge[idx].a, edge[idx].b);
			total += edge[idx].c;
			cnt++;
		}
		idx++;
	}

	cout << total;

	return 0;
}
*/

//Prim
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int v, e;
vector<pair<int, int>> vec[10005];
int dist[10005];
bool check[10005];

int Prim(int r) {
	for (int i = 1; i <= v; i++)
		dist[i] = 2147483647; //INF = 1e9로 하면 작음.
	memset(check, false, sizeof(check));

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, r));
	dist[r] = 0;

	int total = 0;
	while (!pq.empty()) {
		int d, node;
		do {
			node = pq.top().second;
			pq.pop();
		} while (!pq.empty() && check[node]);

		if (check[node])
			break;

		check[node] = true;
		total += dist[node];
		/*
		들어갔던거 들어갈 수 있으므로 do while로 check[node]==true일 경우 pop을 false인 node일때까지 pop해주어야함.
		*/

		for (int i = 0; i < vec[node].size(); i++) {
			if (check[vec[node][i].first] != true && dist[vec[node][i].first]>vec[node][i].second) {
				pq.push(make_pair(vec[node][i].second, vec[node][i].first));
				dist[vec[node][i].first] = vec[node][i].second;
			}
		}
	}

	return total;

}

int main() {
	cin >> v >> e;

	for (int i = 1; i <= e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vec[a].push_back(make_pair(b, c));
		vec[b].push_back(make_pair(a, c));
	}

	int ans = Prim(1);

	cout << ans;

	return 0;
}
