#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int num[25][25];
int check[25][25];
int apartcnt=0;
vector<int> answer;

void dfs(int a, int b) {
	check[a][b] = true;
	apartcnt++;

	if (a + 1 < n&&num[a + 1][b] == 1) {
		if (!check[a + 1][b]) {
			dfs(a + 1, b);
		}
	}
	if (b + 1 < n&&num[a][b+1] == 1) {
		if (!check[a][b+1]) {
			dfs(a, b+1);
		}
	}
	if (0<=a - 1&&num[a - 1][b] == 1) {
		if (!check[a - 1][b]) {
			dfs(a - 1, b);
		}
	}
	if (0<=b - 1&&num[a][b - 1] == 1) {
		if (!check[a][b - 1]) {
			dfs(a, b - 1);
		}
	}
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &num[i][j]);
		}
	}

	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (num[i][j] == 1 && !check[i][j]) {
				apartcnt = 0;
				dfs(i, j);
				answer.push_back(apartcnt);
				count++;
			}
		}
	}

	printf("%d\n", count);
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++) {
		printf("%d\n", answer[i]);
	}

	return 0;
}
