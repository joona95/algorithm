#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int k;
vector<int> lotto;
int check[15];
int cnt = 0;

void dfs(int v) {
	check[v]=true;
	cnt++;

	if (cnt == 6) {
		for (int i = 0; i < k; i++) {
			if(check[i])
				printf("%d ", lotto[i]);
		}
		printf("\n");
	}
	else {
		for (int i = v; i < lotto.size(); i++) {
			if(!check[i])
				dfs(i);
		}
	}

	check[v] = false;
	cnt--;
}

int main() {

	while (1) {
		
		scanf("%d", &k);

		if (k == 0)
			break;

		lotto.clear();
		for (int i = 0; i <= k; i++)
			check[i] = false;

		for (int i = 0; i < k; i++) {
			int n;
			scanf("%d", &n);
			lotto.push_back(n);
		}


		for (int i = 0; i <= k - 6; i++) {
			cnt = 0;
			dfs(i);
		}
		printf("\n");
	}

	return 0;
}