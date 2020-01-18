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

	//��� dp �ױ�
	int d = mem(0, 1);
	printf("%d\n", d);

	//�������
	trace(0, 1);

	return 0;
}

/*
d: �������� �̵��� �Ÿ�

d(f,s): fù��°�������� f�� ������ 2�ι�°�������� s�� ������
������ ������ ��Ǳ��� ó���ϱ� ���� �̵��ؾ� �ϴ� �Ÿ�

d(1,2) = 1->3 : 3
		 2->3 : 6

*/


/*����� ���� : 10272  �� ��ġ���� �δ��� ���ּ��� ���ٰ� �����ϰ� ����ϰ� Ǯ�� �ᱹ �ϳ��� ���°� �ϳ��� ���°�
	 			2666   �������� ��ǥ������ ������ ��ǥx �ΰ������� ���� 2��5���� �ʱ⿡ �ִٰ� ����
*/