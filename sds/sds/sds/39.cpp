#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int depth[100001];
int par[20][100001];
vector<int> vec[100001];
bool visit[100001];

int LCA(int a, int b) {
	if (depth[a] < depth[b]) {
		int tmp = a;
		a = b;
		b = tmp;
	}

	int diff = depth[a] - depth[b];

	int k = 0;
	while (diff >= 1) {
		if(diff%2==1)
			a = par[k][a];
		diff /= 2;
		k++;
	}

	if (a == b) {
		return a;
	}

	for (k = 16; k >= 0&&a!=b; k--) {
		if (par[k][a] != par[k][b]) {
			a = par[k][a];
			b = par[k][b];
		}
	}
	return par[0][a];
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	queue<pair<int, int>> q;
	q.push(make_pair(1, 0));
	visit[1] = true;


	while (!q.empty()) {
		int v = q.front().first;
		int d = q.front().second;
		q.pop();

		for (int i = 0; i < vec[v].size(); i++) {
			if (visit[vec[v][i]] == false) {
				visit[vec[v][i]] = true;
				q.push(make_pair(vec[v][i], d + 1));
				par[0][vec[v][i]] = v;
				depth[vec[v][i]] = d + 1;
			}
		}
	}

	/*
	for (int i = 1; i <= n; i++) {
		printf("%d ", depth[i]);
	}
	printf("\n");
	for (int i = 1; i <= n; i++) {
		printf("%d ", par[0][i]);
	}*/

	//0 1 1 2 2 2 2 2 3 3 3 3 3 3 4
	//0 1 1 2 2 2 3 3 4 4 5 5 7 7 11

	for (int i = 1; i <= 17; i++) {
		for (int j = 1; j <= n; j++) {
			par[i][j] = par[i - 1][par[i - 1][j]];
		}
	}
	
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);

		printf("%d\n", LCA(a, b));
	}
	
	



	return 0;
}

/*
*/