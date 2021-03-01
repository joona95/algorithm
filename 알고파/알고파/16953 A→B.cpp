#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <queue>

using namespace std;

queue<pair<int, int>> q;

int main() {
	int a, b;
	scanf("%d %d", &a, &b);

	q.push(make_pair(a, 1));
	int answer = -1;

	while (!q.empty()) {
		int n = q.front().first;
		int cnt = q.front().second;
		q.pop();
		
		if (n == b) {
			answer = cnt;
			break;
		}

		if (n<= 100000000) { //n*10+1�� ���� ��� int ������ �Ѿ. max��/10�� ��.
			q.push(make_pair(n * 10 + 1, cnt + 1));
		}
		if (2 * n <= b) {
			q.push(make_pair(2 * n, cnt + 1));
		}
	}

	printf("%d", answer);

	return 0;
}

/*
�Ųٷ� Ǯ�� ����� ����
https://docs16.tistory.com/69
*/