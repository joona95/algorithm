#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

int parent[1000005];

class DisjointSet {
public:
	DisjointSet(int n) {
		for (int i = 0; i <= n; i++) {
			parent[i] = i;
		}
	}

	void Union(int a, int b) {
		int aRoot = Find(a);
		int bRoot = Find(b);
		parent[aRoot] = bRoot;
	}

	int Find(int a) {
		if (parent[a] == a)
			return a;
		else
			return parent[a] = Find(parent[a]);
	}
};

int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	DisjointSet d(n);

	for (int i = 0; i < m; i++) {
		int c, a, b;
		scanf("%d%d%d", &c, &a, &b);

		

		if (c == 0) {
			d.Union(a, b);
		}
		else if (c == 1) {
			if (d.Find(a) == d.Find(b)) {
				printf("YES\n");
			}
			else {
				printf("NO\n");
			}
		}
	}

	return 0;
}

/*
1000000 -> 1초 -> O(n) 알고리즘
*/
