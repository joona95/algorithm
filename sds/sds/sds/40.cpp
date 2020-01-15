#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int,int>> vec[100001];
int depth[100001];
int par[20][100001];
int dmin[20][100001];
int dmax[20][100001];
bool visit[100001];

int min(int a, int b) {
	if (a > b)
		return b;
	else
		return a;
}

int max(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i < n; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		vec[a].push_back(make_pair(b,c));
		vec[b].push_back(make_pair(a,c));
	}

	for (int k = 0; k < 20; k++) {
		for (int i = 0; i <= n; i++) {
			dmin[k][i] = 100001;
			dmax[k][i] = 0;
		}
	}

	queue<int> q;
	q.push(1);
	visit[1] = true;
	depth[1] = 0;

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		for (int i = 0; i < vec[v].size(); i++) {
			if (visit[vec[v][i].first] == false) {
				visit[vec[v][i].first] = true;
				q.push(vec[v][i].first);
				depth[vec[v][i].first] = depth[v] + 1;
				par[0][vec[v][i].first] = v;
				dmin[0][vec[v][i].first] = vec[v][i].second;
				dmax[0][vec[v][i].first] = vec[v][i].second;
			}
		}
	}

	for (int k = 1; k < 20; k++) {
		for (int i = 1; i <= n; i++) {
			par[k][i] = par[k - 1][par[k - 1][i]];
			dmin[k][i] = min(dmin[k-1][i],dmin[k-1][par[k-1][i]]);
			dmax[k][i] = max(dmax[k-1][i],dmax[k-1][par[k-1][i]]);
		}
	}

	/*
	for (int k = 0; k < 20; k++) {
		for (int i = 1; i <= n; i++) {
			printf("%d ", dmin[k][i]);
		}
		printf("\n");
	}
	printf("\n***\n");
	for (int k = 0; k < 20; k++) {
		for (int i = 1; i <= n; i++) {
			printf("%d ", dmax[k][i]);
		}
		printf("\n");
	}*/


	int K;
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		int d, e;
		scanf("%d%d", &d, &e);

		int min_v = 1000001, max_v = -1;

		if (depth[d] < depth[e]) {
			int tmp = d;
			d = e;
			e = tmp;
		}

		int diff = depth[d] - depth[e];
		int kk = 0;
		while (diff >= 1) {
			if (diff % 2 == 1) {
				min_v = min(min_v, dmin[kk][d]);
				max_v = max(max_v, dmax[kk][d]);
				d = par[kk][d];
			}
			diff /= 2;
			kk++;
		}

		for (int k = 19; k >= 0&&d!=e; k--) {
			if (par[k][d] != par[k][e]) {
				min_v = min(min_v, min(dmin[k][d], dmin[k][e]));
				max_v = max(max_v, max(dmax[k][d], dmax[k][e]));
				d = par[k][d];
				e = par[k][e];
			}
		}
		

		if (d != e) {
			min_v = min(min_v, min(dmin[0][d], dmin[0][e]));
			max_v = max(max_v, max(dmax[0][d], dmax[0][e]));
		}
		printf("%d %d\n", min_v, max_v);
		
	}




	return 0;
}

//도로 네트워크 -> LCA
//트리

/*
1 2 3 4 5
0 3 1 3 1
0 1 0 1 0
0 0 0 0 0
0 100 50 200 150

2 4
3 5
1 2

*/