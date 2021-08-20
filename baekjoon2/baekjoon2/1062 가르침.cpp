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
			for (int k = 4; k < len-4; k++) { //�� �ڷ� anta / tica ����
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
	�̺κ��� main���� �� �� �õ����� �� 0���� �����ؼ� �� ���� �ɸ��� 
	�׷��� �ƿ� main���� ������ �ȵǵ��� �ϰų� main�� dfs(0,idx+1)�� �ƴ϶� dfs(i+1, idx+1)�� �ؾ�����
	*/
	for (int i = r; i < 26; i++) { //ABCD, BACD, BCAD �� ���� �����ѵ� ������ �ٸ� ���� ���� ����
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
//DFS ���Ʈ����


/*
�ð��ʰ� ������ �ʹ� ����ߴ�
*/