#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int n, k;
set<string> s;
vector<int> v;
vector<int> sel;
bool visit[15];

void card(int depth) {
	if (k == depth) {
		string str = "";
		for (int i = 0; i < sel.size(); i++) {
			str.append(to_string(sel[i]));
		}

		s.insert(str);
		return;
	}

	int idx;
	for (int i = 0; i < n; i++) {
		if (visit[i] == false) {
			visit[i] = true;
			sel.push_back(v[i]);
			card(depth + 1);
			visit[i] = false;
			sel.pop_back();
		}
	}
}

int main() {
	scanf("%d%d", &n, &k);

	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	card(0);

	printf("%d", s.size());

	return 0;
}
//카드 넣기

/*
5 3
1 2 3 / 13 21

1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
2 1 13
21 1 3

3*2*1


4 2
1 1 2 / 12
3*2/2 + 1 -1 = 3
2*1 + 1*2 - 0


*/