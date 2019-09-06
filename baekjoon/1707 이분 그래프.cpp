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



//�̺� �׷��� : ������ ������ �ѷ� ������ �� ���տ� ���� ���������� ���� �������� �ʵ��� ���� ������ �׷���
//�������� ���� 0, ������ ������ dfs�� ���� 1��2�� ������ ǥ��
//�� �� ��� �������� ������ ������ �ٸ� ������ Ȯ��
//vector, visit �ʱ�ȭ