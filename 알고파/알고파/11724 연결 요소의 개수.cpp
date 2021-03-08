#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int m, n, k;
vector<int> num[1001];
bool check[1001];

void bfs(int v) {
	queue<int> q;
	q.push(v);

	while (!q.empty()) {
		int front = q.front();
		q.pop();
		check[front] = true;

		for (int i = 0; i < num[front].size(); i++) {
			if (!check[num[front][i]]) {
				q.push(num[front][i]);
				check[num[front][i]] = true;
			}
		}
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);

		num[u].push_back(v);
		num[v].push_back(u);
	}

	int answer = 0;
	for (int i = 1; i <= n; i++) {
		
		if (!check[i]) {
			bfs(i);
			answer++;
		}
		
	}

	printf("%d", answer);

	return 0;
}