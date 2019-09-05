#include <iostream>
#include <stack>
using namespace std;

bool arr[1001][1001] = { 0, };
bool visit[1001] = { 0, };
int total=0, cnt = 0;
int DFS(int x, int n) {
	stack<int> s;
	s.push(x);
	while (!s.empty()) {
		int r = s.top();
		cout <<"r:"<< r << endl;
		s.pop();
		if (!visit[r]) {
			cnt++;
			cout << "cnt:"<<cnt << endl;
			visit[r] = true;
			for (int i = n; i > 0; i--) {
				if (arr[r][i] && !visit[i]) {
					s.push(i);
				}
			}
		}
	}
	total++;

	if (cnt == n) {
		return total;
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (!visit[i]) {
				return DFS(i,n);
				break;
			}
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		arr[u][v] = true;
		arr[v][u] = true;
	}

	cout<<DFS(1, n);

	return 0;
}

//int���Լ��� return �ϴ� �Ͱ� void�� �Լ������� cout �ٷ� �ϴ� ��: �ٷ��ϴ°� �ð��� ���� �� ����
