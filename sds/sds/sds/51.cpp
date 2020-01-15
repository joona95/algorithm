//2020.01.15
//11400

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
	int from, to;
};

vector<Edge> edges;
vector<int> vec[100005];
int discover[100005];

int order = 0;

bool cmp(Edge a, Edge b) {
	if (a.from < b.from) {
		return true;
	}
	else if (a.from > b.from) {
		return false;
	}
	else {
		if (a.to < b.to) {
			return true;
		}
		else
			return false;
	}
}

int min(int a, int b) {
	if (a > b)
		return b;
	else
		return a;
}

int DFS(int r, int par) {
	discover[r] = ++order;
	int low = discover[r];

	for (int i = 0; i < vec[r].size(); i++) {
		if (vec[r][i] == par)
			continue;

		if (discover[vec[r][i]]) {
			low = min(low, discover[vec[r][i]]);
		}
		else {
			int pre_low=DFS(vec[r][i],r);
		
			if (pre_low > discover[r]) {
				Edge tmp;
				if (r < vec[r][i]) {
					tmp.from = r;
					tmp.to = vec[r][i];
				}
				else {
					tmp.from = vec[r][i];
					tmp.to = r;
				}
				edges.push_back(tmp);
			}

			low = min(low, pre_low);
		}
	}


	return low;
}

int main() {
	int v, e;
	scanf("%d%d", &v, &e);

	for (int i = 0; i < e; i++) {
		int a, b;
		scanf("%d%d", &a, &b);

		vec[a].push_back(b);
		vec[b].push_back(a);

	}

	for (int i = 1; i <= v; i++) {
		if (!discover[i])
			DFS(i,0);
	}

	printf("%d\n", edges.size());

	sort(edges.begin(), edges.end(),cmp);

	for (int i = 0; i < edges.size(); i++) {
		printf("%d %d\n", edges[i].from, edges[i].to);
	}

	return 0;
}

/*

*/