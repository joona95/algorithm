#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
int M[30][30];
int dist[30][30];
bool check[30][30];
int main() {
	int n, m, t, d;
	scanf("%d%d%d%d\n", &n, &m, &t, &d);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= m; j++) {
			char c;
			scanf("%c", &c);
			if (65 <= c && c <= 90) {
				M[i][j] = c - 65;
			}
			else if (97 <= c && c <= 122) {
				M[i][j] = c - 71;
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (0 <= i - 1&&abs(M[i][j]-M[i-1][j])<=t)
				dist[i - 1][j] = dist[i][j] + pow(M[i][j] - M[i - 1][j],2);
			if (0 <= j - 1 && abs(M[i][j] - M[i][j - 1]) <= t)
				dist[i][j - 1] = dist[i][j] + pow(M[i][j] - M[i][j - 1], 2);
			if (i + 1 < n&&abs(M[i][j] - M[i + 1][j]) <= t)
				dist[i + 1][j] = dist[i][j] + pow(M[i][j] - M[i + 1][j], 2);
			if (j + 1 < m&&abs(M[i][j] - M[i][j + 1]) <= t)
				dist[i][j + 1] = dist[i][j] + pow(M[i][j] - M[i][j + 1], 2);
			//printf("%d ", M[i][j]);
		}
		printf("\n");
	}


	
	return 0;
}

/*
6 6 6 36
0  0  1  2  3  4
6  9  8  7  6  5
12 10 11 12 13 14
18 19 18 17 16 15
24 20 21 22 23 24
30 29 28 27 26 25

(0,0)->(x,y) 가는 경우
0  1  2  3  4  5
19 10 9  8  7  6 
15 11 12 13 14 15
21 20 19 18 17 16
37 21 22 23 24 25
31 30 29 28 27 26

(x,y)->(0,0) 가능 경우 나눠서 생각해보기
0  1  2 ...

31+5<=36

*/