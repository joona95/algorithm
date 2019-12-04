#include <cstdio>
#include <vector>
using namespace std;

struct Disjointset {
	vector<int> par;

	Disjointset(int n) {
		par.resize(n + 5, -1);
	}

	int f(int x) {
		if (par[x] == -1)
			return x;
		return par[x] = f(par[x]);
	}

	void u(int x, int y) {
		x = f(x);
		y = f(y);
		if (x == y)
			return;
		par[x] = y;
	}

	void print(int x, int y) {
		x = f(x);
		y = f(y);
		if (x == y)
			printf("YES\n");
		else
			printf("NO\n");
	}
};

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	Disjointset d= Disjointset(n);

	for (int i = 1; i <= m; i++) {
		int s, a, b;
		scanf("%d %d %d", &s, &a, &b);

		if (s == 0) {
			d.u(a, b);
		}
		else {
			d.print(a, b);
		}

	}

	return 0;
}
/*시간초과 cin, cout >> scanf, printf 로 해결*/