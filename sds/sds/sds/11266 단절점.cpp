//2020.01.15
//11266
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>

using namespace std;

vector<int> vec[10005];
int discover[10005];
bool isCut[10005];

int order = 0;

int min(int a, int b) {
	if (a > b)
		return b;
	else
		return a;
}

int DFS(int r, bool isRoot) {
	discover[r] = ++order;
	int low = discover[r];

	int child = 0;

	for (int i = 0; i < vec[r].size(); i++) {
		if (discover[vec[r][i]]) {
			low = min(low, discover[vec[r][i]]);
		}
		else {

			child++;
			int pre_low = DFS(vec[r][i], false);

			if (!isRoot&&pre_low >= discover[r]) {
				isCut[r] = true;
			}

			low = min(low, pre_low);
		}
	}

	if (isRoot) {
		if (child >= 2)
			isCut[r] = true;
		else
			isCut[r] = false;
	}

	return low;
}

int main() {
	int v, e;
	scanf("%d%d", &v, &e);
	for (int i = 1; i <= e; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	for (int i = 1; i <= v; i++) {
		if (!discover[i]) {
			DFS(i,true);
		}
	}
	
	int cnt = 0;
	for (int i = 1; i <= v; i++) {
		if (isCut[i])
			cnt++;
	}

	printf("%d\n", cnt);
	for (int i = 1; i <= v; i++) {
		if (isCut[i])
			printf("%d ", i);
	}

	return 0;
}