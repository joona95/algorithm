#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
using namespace std;

int arr[105][105];
bool visit[105][105];
queue<pair<pair<int, int>, int>> q;
int main() {
	int n, m;
	scanf("%d %d\n", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m+1; j++) {
			char c;
			scanf("%c", &c);
			if (c == '0')
				arr[i][j] = 0;
			else if (c == '1')
				arr[i][j] = 1;
		}
	}


	q.push(make_pair(make_pair(1, 1), 1));
	visit[1][1] = 1;
	int cnt;
	while (!q.empty()) {
		pair<pair<int, int>,int> idx = q.front();
		q.pop();
		cnt = idx.second;		

		if (idx.first.first == n && idx.first.second == m) {
			break;
		}

		if (idx.first.first + 1 <= n && visit[idx.first.first + 1][idx.first.second] == 0 && arr[idx.first.first + 1][idx.first.second] == 1) {
			arr[idx.first.first + 1][idx.first.second] = 1;
			q.push(make_pair(make_pair(idx.first.first + 1, idx.first.second), idx.second + 1));
			visit[idx.first.first+1][idx.first.second] = 1;
		}
		if (idx.first.first - 1 >0 && visit[idx.first.first - 1][idx.first.second] == 0 && arr[idx.first.first - 1][idx.first.second] == 1) {
			arr[idx.first.first - 1][idx.first.second] = 1;
			q.push(make_pair(make_pair(idx.first.first - 1, idx.first.second), idx.second + 1));
			visit[idx.first.first-1][idx.first.second] = 1;
		}
		if (idx.first.second + 1 <= m && visit[idx.first.first][idx.first.second+1] == 0 && arr[idx.first.first][idx.first.second+1] == 1) {
			arr[idx.first.first][idx.first.second+1] = 1;
			q.push(make_pair(make_pair(idx.first.first, idx.first.second+1), idx.second + 1));
			visit[idx.first.first][idx.first.second+1] = 1;
		}
		if (idx.first.second-1 >0 && visit[idx.first.first][idx.first.second-1] == 0 && arr[idx.first.first][idx.first.second-1] == 1) {
			arr[idx.first.first][idx.first.second-1] = 1;
			q.push(make_pair(make_pair(idx.first.first, idx.first.second-1), idx.second + 1));
			visit[idx.first.first][idx.first.second-1] = 1;
		}
	}

	/*
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			printf("%d ", visit[i][j]);
		}
		printf("\n");
	}*/

	printf("%d\n", cnt);
	
	return 0;
}

/*
push할때 visit 체크해줘야함.
아니면 중복된 값이 queue에 여러번 들어가므로 메모리 초과가 뜬다.
*/