#define _CRT_SECURE_NO_WARNINGS


#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;


struct Edge {
	int v1;
	int v2;
	int cost;
};

class DisjointSet {
public:
	int par[1005];

	DisjointSet(int n) {
		for (int i = 1; i <= n; i++) {
			par[i] = i;
		}
	}

	void Union(int a, int b) {
		int aRoot = Find(a);
		int bRoot = Find(b);

		par[aRoot] = bRoot;
	}

	int Find(int a) {
		if (par[a] == a) {
			return a;
		}
		else {
			return par[a] = Find(par[a]);
		}
	}
};


bool cmp(Edge a, Edge b) {
	if (a.cost < b.cost)
		return true;
	else
		return false;
}

vector<Edge> edge;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	DisjointSet d(n);

	for (int i = 0; i < m; i++) {
		Edge e;
		scanf("%d%d%d", &(e.v1), &(e.v2), &(e.cost));

		edge.push_back(e);
	}

	sort(edge.begin(), edge.end(),cmp);

	int total = 0;
	for (int i = 0; i < edge.size(); i++) {
		int v1 = edge[i].v1;
		int v2 = edge[i].v2;
		int c = edge[i].cost;

		if (d.Find(v1) != d.Find(v2)) {
			d.Union(v1, v2);
			total += c;
		}
	}

	printf("%d", total);
}
//네트워크 연결

/*
크루스칼: O(ElogE)
프림: O(V^2)

1 2 5
1 3 4
2 3 2 
2 4 7
3 4 6
3 5 11
4 5 3 
4 6 8
5 6 8


Q.개미굴
최소신장트리 구하고
빠진 간선포함하여 나온 cycle에서 빠졌던 간선과 동일한 비용인 경우의 수를 찾으면


Q.배제쌍

*/