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
n이 0과 같은 경우가 존재함. => 1로 시작.
-1인 경우: 가득 차 있으며 제일 맨 끝의 값보다 작거나 같은 경우.
*/