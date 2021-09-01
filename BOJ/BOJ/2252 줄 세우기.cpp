#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<int> edge[32001];
int degree[32001];

void topologicalSort() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (degree[i] == 0) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		printf("%d ", v);
		for (int i = 0; i < edge[v].size(); i++) {
			int next = edge[v][i];
			if (degree[next] <= 0) {
				continue;
			}
			degree[next]--;
			if (degree[next] == 0) {
				q.push(next);
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		edge[a].push_back(b);
		degree[b]++;
	}
	topologicalSort();
	return 0;
}

/*
위상정렬
*/