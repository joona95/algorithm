#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

using namespace std;

int scores[50];

int main() {
	int n, score, p;
	scanf("%d %d %d", &n, &score, &p);

	for (int i = 0; i < n; i++) {
		scanf("%d", &scores[i]);
	}

	int answer = 1;
	for (int i = 0; i < n; i++) {
		if (scores[i]>score) {
			answer++;
		}
		else {
			break;
		}
	}

	if (n==p&&scores[n-1]>=score) {
		answer = -1;
	}

	printf("%d", answer);

	return 0;
}

/*
n�� 0�� ���� ��찡 ������. => 1�� ����.
-1�� ���: ���� �� ������ ���� �� ���� ������ �۰ų� ���� ���.
*/