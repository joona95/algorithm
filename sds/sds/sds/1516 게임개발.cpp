#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector<int> vec[505];
int arr[505];
int time[505];
int cost[505];

int max(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &time[i]);

		int num;
		scanf("%d", &num);

		while (num != -1) {
			arr[i]++;

			vec[num].push_back(i);
			scanf("%d", &num);
		}
	}
	
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (arr[i] == 0) {
			q.push(i);
			cost[i] = time[i];
		}
	}


	while (!q.empty()) {
		int v = q.front();
		//printf("%d ", v);
		q.pop();

		for (int i = 0; i < vec[v].size(); i++) {
			arr[vec[v][i]]--;
			cost[vec[v][i]] = max(cost[vec[v][i]], time[vec[v][i]] + cost[v]);
			if (arr[vec[v][i]] == 0) {
				q.push(vec[v][i]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		printf("%d\n", cost[i]);
	}

	return 0;
}

/*
4
20 -1
10 -1
1 1 2 -1
1000 1 2 3 -1

20 10 21 1021
*/