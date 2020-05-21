#define _CRT_SEUCRE_NO_WARNINGS

#include <cstdio>
#include <cstring>

char word[55][20];
bool visited[26];
int n, k;
int cnt = 0;

int DFS(int r) {
	for (int i = 0; i < n; i++) {
		for (int j = 4; j < strlen(word[i]) - 4; j++) {

		}
	}
}


int main() {
	scanf("%d %d\n", &n, &k);

	//a n t i c
	visited['a' - 'a'] = true;
	visited['c' - 'a'] = true;
	visited['i' - 'a'] = true;
	visited['n' - 'a'] = true;
	visited['t' - 'a'] = true;

	for (int i = 0; i < n; i++) {
		scanf("%s", word[i]);
	}

	

	for (int i = 0; i < 26; i++) {
		if (visited[i] != true) {
			DFS(i);
		}
	}

	return 0;
}
//DFS?? 브루트포스


/*
(a)b(c)defgh(i)jklm(n)opqrs(t)uvwxyz
anta rc tica=>r
anta hello tica=>h e l o
anta car tica=>r


*/