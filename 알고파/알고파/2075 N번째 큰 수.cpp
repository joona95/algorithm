#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <queue>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int num;
			scanf("%d", &num);

			if (pq.size() < n) {
				pq.push(num);
			}
			else {
				if (pq.top() < num) {
					pq.pop();
					pq.push(num);
				}
			}
		}
	}

	
	printf("%d", pq.top());

	return 0;
}

/*
priority queue�� ���� ��������ϱ� �޸� �ʰ�
dp�� size�����ؼ� min ã�Ƽ� �ϴϱ� �ð� �ʰ�
priority queue�� size �����ϴ°� ����!
*/