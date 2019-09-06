#include <iostream>
#include <vector>
using namespace std;
int k, v, e;
vector<int> vec[20001];
int visit[20001];

void DFS(int r, int c) {
	if (!visit[r]) {
		visit[r] = c;
		for (int i = 0; i < vec[r].size(); i++) {
			if (!visit[vec[r][i]]) {
				DFS(vec[r][i], 3 - c);
			}
		}
	}
}



int main() {
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> v >> e;

		for (int i = 0; i <= v; i++) {
			vec[i].clear();
		}

		for (int i = 0; i < e; i++) {
			int x, y;
			cin >> x >> y;
			vec[x].push_back(y);
			vec[y].push_back(x);
		}

		for (int i = 0; i <= v; i++) {
			visit[i] = 0;
		}

		
		for (int i = 1; i <= v; i++) {
			if (!visit[i]) {
				DFS(i, 1);
			}
		}
		


		bool bi = true;
		for (int i = 1; i <= v; i++) {
			for (int j = 0; j < vec[i].size(); j++) {
				if (visit[i] == visit[vec[i][j]]) {
					bi = false;
					break;
				}
			}
		}

		if (bi == true) {
			cout << "YES" << "\n";
		}
		else {
			cout << "NO" << "\n";
		}

	}
	return 0;
}



//이분 그래프 : 정점의 집합을 둘로 나누어 각 집합에 속한 정점끼리는 서로 인접하지 않도록 분할 가능한 그래프
//안지나간 정점 0, 지나간 정점을 dfs를 통해 1과2로 나누어 표시
//그 후 모든 정점에서 인접한 정점이 다른 색인지 확인
//vector, visit 초기화