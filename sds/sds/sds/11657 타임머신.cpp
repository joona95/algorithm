#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>

using namespace std;

vector<pair<int, int>> vec[505];
int dist[505];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);

		vec[a].push_back(make_pair(b, c));
	}

	for (int i = 1; i <= n; i++) {
		dist[i] = 1e9;
	}

	bool isCycle = false;
	dist[1] = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[j] != 1e9) {
				for (int k = 0; k < vec[j].size(); k++) {
					int v = vec[j][k].first;
					int c = vec[j][k].second;

					if (dist[v] > dist[j] + c) {
						dist[v] = dist[j] + c;

						if (i == n) {
							isCycle = true;
						}
					}
				}
			}
		}
	}

	if (isCycle == true) {
		printf("-1\n");
	}
	else {
		for (int i = 2; i <= n; i++) {
			if (dist[i] != 1e9)
				printf("%d\n", dist[i]);
			else
				printf("-1\n");
		}
	}


	return 0;
}