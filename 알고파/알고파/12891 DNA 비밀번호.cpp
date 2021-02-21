#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

using namespace std;

int A[1000001];
int C[1000001];
int G[1000001];
int T[1000001];

int main() {
	int s, p;
	scanf("%d %d\n", &s, &p);

	for (int i = 1; i <=s; i++) {
		char ch;
		scanf("%c", &ch);

		if (ch == 'A') {
			A[i] = A[i - 1] + 1;
		}
		else {
			A[i] = A[i - 1];
		}

		if (ch == 'C') {
			C[i] = C[i - 1] + 1;
		}
		else {
			C[i] = C[i - 1];
		}

		if (ch == 'G') {
			G[i] = G[i - 1] + 1;
		}
		else {
			G[i] = G[i - 1];
		}

		if (ch == 'T') {
			T[i] = T[i - 1] + 1;
		}
		else {
			T[i] = T[i - 1];
		}
	}

	int a, c, g, t;
	scanf("%d %d %d %d", &a, &c, &g, &t);

	int answer = 0;
	for (int i = p; i <= s; i++) {
		if ((A[i] - A[i - p] >= a) && (C[i] - C[i - p] >= c) && (G[i] - G[i - p] >= g) && (T[i] - T[i - p] >= t)) {
			answer++;
		}
	}

	printf("%d", answer);

	return 0;
}