#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int arr[32005];
vector<int> vec[32005];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	
	

	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);

		arr[b]++;
		vec[a].push_back(b);
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (arr[i] == 0) {
			q.push(i);
			printf("%d ", i);
		}
	}

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		for (int i = 0; i < vec[v].size(); i++) {
			arr[vec[v][i]] --;

			if (arr[vec[v][i]] == 0) {
				q.push(vec[v][i]);
				printf("%d ", vec[v][i]);
			}
		}

	}

	return 0;
}

/*
O(V+E)
��������
*/

/*
3 2
1 2 3
0 0 2

4 2
1 2 3 4 
1 1 0 0




Q.����
1 2
2 3
3 4

���°� ����� Union�� �Ųٷ� Ǯ���

Q.������
���°� Union �Ųٷ�.
4 2 5 3
1 2 3 3 
1 2 5 5

4   5
1 
1   5 5

���ʷ� bfs�� � �ִ��� �˾Ƴ���..?

*/

/*
Q.��½ױ�
6 4 1 3
1->4
1->3
1->6
1->4->6
1->3->6
4->6
3->6

1 3 4 6


*/