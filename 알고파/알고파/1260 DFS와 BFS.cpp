#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> num[1001];
bool check[1001];

void dfs(int v) {
	check[v] = true;
	printf("%d ", v);
	for (int i = 0; i < num[v].size(); i++) {
		if(!check[num[v][i]])
			dfs(num[v][i]);
	}
}

void bfs(int v) {
	queue<int> q;

	q.push(v);

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		check[x] = true;
		printf("%d ", x);

		for (int i = 0; i < num[x].size(); i++) {
			if (!check[num[x][i]]) {
				q.push(num[x][i]);
				check[num[x][i]] = true;
			}
		}
	}
}

int main() {
	int n, m, v;
	scanf("%d %d %d", &n, &m, &v);

	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		num[a].push_back(b);
		num[b].push_back(a);
	}
	for (int i = 0; i <= n; i++) {
		sort(num[i].begin(), num[i].end());
	}

	dfs(v);
	for (int i = 0; i <= n; i++)
		check[i] = false;
	printf("\n");
	bfs(v);

	return 0;
}

//sort해줘야함 더 작은 거 먼저 방문한다고 문제에 있음