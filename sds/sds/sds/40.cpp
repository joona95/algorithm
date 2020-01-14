#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int,int>> vec[100001];
int depth[100001];
int par[18][100001];
bool visit[100001];
int dmax[18][100001];
int dmin[18][100001];

int min(int a,int b) {
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

	for (int i = 0; i <= 17; i++) {
		for (int j = 1; j <= n; j++) {
			dmax[i][j] = 0;
			dmin[i][j] = 1000001;
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
				dmax[0][vec[v][i].first] = vec[v][i].second;
				dmin[0][vec[v][i].first] = vec[v][i].second;
			}
		}
	}

	for (int i = 1; i <= 17; i++) {
		for (int j = 1; j <= n; j++) {
			par[i][j] = par[i - 1][par[i - 1][j]];
			dmax[i][j] = max(dmax[i-1][j],dmax[i-1][par[i-1][j]]);
			dmin[i][j] = min(dmin[i-1][j],dmin[i-1][par[i-1][j]]);
		}
	}



	/*
	for (int i = 1; i <= n; i++)
		printf("%d ", dmax[0][i]);
	printf("\n");
	for (int i = 1; i <= n; i++)
		printf("%d ", dmin[0][i]);
		*/

	int k;
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int d, e;
		scanf("%d%d", &d, &e);

		int min_v=1000001, max_v = -1;


		if (depth[d] < depth[e]) {
			int tmp = d;
			d = e;
			e = tmp;
		}

		//

		for (int j = 17; j >= 0 && d != e; j--) {
			if (par[j][d] != par[j][e]) {
				min_v = min(min_v, min(dmin[j][d], dmin[j][e]));
				max_v = max(max_v, max(dmax[j][d], dmax[j][e]));
				d = par[j][d];
				e = par[j][e];
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