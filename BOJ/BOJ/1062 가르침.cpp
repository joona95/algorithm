#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>

using namespace std;

char word[55][20];
bool visited[26];
int n, k;
int answer = 0;

void dfs(int r, int idx) {
	if (idx == k) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			int l = 0;
			int len = strlen(word[i]);
			for (int k = 4; k < len-4; k++) { //앞 뒤로 anta / tica 제거
				if (!visited[word[i][k] - 'a']) {
					break;
				}
				l++;
			}
			if (l == len-8) {
				cnt++;
			}
		}
		if (answer < cnt) {
			answer = cnt;
		}
		return;
	}
	/*
	이부분을 main에서 한 번 시도해줄 때 0부터 시작해서 더 오래 걸린듯 
	그래서 아예 main에서 진행이 안되도록 하거나 main도 dfs(0,idx+1)이 아니라 dfs(i+1, idx+1)로 해야했음
	*/
	for (int i = r; i < 26; i++) { //ABCD, BACD, BCAD 등 같은 동일한데 순서만 다른 여러 조합 방지
		if (!visited[i]) {
			visited[i] = true;
			dfs(i + 1, idx + 1);
			visited[i] = false;
		}
	}
}

int main() {
	scanf("%d %d\n", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%s", word[i]);
	}
	visited['a' - 'a'] = true;
	visited['c' - 'a'] = true;
	visited['i' - 'a'] = true;
	visited['n' - 'a'] = true;
	visited['t' - 'a'] = true;
	if (k < 5) {
		printf("0");
		return 0;
	}
	dfs(0, 5);
	printf("%d", answer);
	return 0;
}
//DFS 브루트포스


/*
시간초과 때문에 너무 고생했다
*/