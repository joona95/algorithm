//3830
//union find?

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>

using namespace std;

//vector<pair<int, int>> vec[100005];
int par[100005];
//bool visit[100005];
long long dist[100005];


int Find(int a) {
	if (par[a] == a)
		return a;

	int par_a = Find(par[a]);
	dist[a] += dist[par[a]];
	
	return par[a] = par_a;
}

void Union(int a, int b, int w) {
	int aRoot = Find(a);
	int bRoot = Find(b);
	if (aRoot == bRoot)
		return;

	dist[bRoot] = dist[a] - dist[b] + w;
	par[bRoot] = aRoot;
	

}

/*
void dfscost(int a, int b) {

	if (a == b) {

		return;
	}
	visit[a] = true;

	for (int i = 0; i < vec[a].size(); i++) {
		int u = vec[a][i].first;
		int c = vec[a][i].second;
		if (!visit[u]) {
			total+=c;
			dfscost(u, b);
			total-=c;
		}
	}

	visit[a] = false;
	
}*/

int main() {
	while (1) {
		int n, m;
		scanf("%d%d", &n, &m);

		if (n == 0 && m == 0)
			break;

		for (int i = 1; i <= n; i++) {
			par[i] = i;
			dist[i] = 0;
			//vec[i].clear();
		}

		for (int i = 0; i < m; i++) {
			char c[2];
			scanf("%s", c);

			if (c[0] == '!') {
				int a, b, w;
				scanf("%d%d%d", &a, &b, &w);
				//vec[a].push_back(make_pair(b, w));
				//vec[b].push_back(make_pair(a, -w));

				Union(a, b, w);
				
				/*
				for (int j = 1; j <= n; j++) {
					printf("%d ", dist[j]);
				}
				printf("\n");
				for (int j = 1; j <= n; j++) {
					printf("%d ", par[j]);
				}
				printf("\n");
				*/
				
			}
			else if (c[0] == '?') {
				int a, b;
				scanf("%d%d", &a, &b);

				if (Find(a) == Find(b)) {
					printf("%lld\n", dist[b] - dist[a]);
					
				}
				else {
					printf("UNKNOWN\n");
				}
			}
		}
	}

	return 0;
}