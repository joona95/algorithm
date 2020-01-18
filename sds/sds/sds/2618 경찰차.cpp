#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <utility>

using namespace std;

int n, w;
vector<pair<int, int>> cases;
int dp[1005][1005];
vector<int> ans;

int max(int a, int b) {
	return (a > b ? a : b);
}

int min(int a, int b) {
	return (a > b ? b : a);
}

int dist(pair<int, int> a, pair<int, int> b) {
	
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int mem(int f, int s) {
	if (f == w + 1 || s == w + 1)
		return 0;

	if (dp[f][s] != 0)
		return dp[f][s];

	int next = max(f, s) + 1;
	int p1 = mem(next, s) + dist(cases[f], cases[next]);
	int p2 = mem(f, next) + dist(cases[s], cases[next]);
	dp[f][s] = min(p1, p2);
	return dp[f][s];
}

void trace(int f, int s) {
	if (f == w + 1 || s == w + 1) {
		for (int i = 0; i < ans.size(); i++) {
			printf("%d\n", ans[i]);
		}
		return;
	}

	int next = max(f, s) + 1;
	int p1 = dp[next][s] + dist(cases[f], cases[next]);
	int p2 = dp[f][next] + dist(cases[s], cases[next]);

	if (p1 < p2) {
		ans.push_back(1);
		trace(next, s);
	}
	else {
		ans.push_back(2);
		trace(f, next);
	}

	return;
}

int main() {
	scanf("%d%d", &n,&w);

	cases.push_back(make_pair(1, 1));
	cases.push_back(make_pair(n, n));

	for (int i = 1; i <= w; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		cases.push_back(make_pair(x, y));
	}

	//경로 dp 쌓기
	int d = mem(0, 1);
	printf("%d\n", d);

	//경로추적
	trace(0, 1);

	return 0;
}

/*
d: 경찰차가 이동한 거리

d(f,s): f첫번째경찰차가 f에 있을때 2두번째경찰차가 s에 있을때
앞으로 마지막 사건까지 처리하기 위해 이동해야 하는 거리

d(1,2) = 1->3 : 3
		 2->3 : 6

*/


/*비슷한 문제 : 10272  한 위치에서 두대의 우주선이 간다고 생각하고 비슷하게 풀면 결국 하나는 가는거 하나는 오는거
	 			2666   경찰차는 좌표였지만 벽장은 좌표x 두경찰차가 벽장 2번5번에 초기에 있다고 생각
*/