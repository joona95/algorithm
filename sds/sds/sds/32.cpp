#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>

int arr[10005];

class Queue {
public:
	int s_idx = 0;
	int e_idx = -1;

	void push(int x) {
		arr[++e_idx] = x;
	}

	int pop() {
		if (s_idx <= e_idx) {
			return arr[s_idx++];
		}
		else {
			return -1;
		}
	}

	int size() {
		return e_idx - s_idx + 1;
	}

	int empty() {
		if (s_idx <= e_idx) {
			return 0;
		}
		else {
			return 1;
		}
	}

	int front() {
		if (s_idx <= e_idx) {
			return arr[s_idx];
		}
		else {
			return -1;
		}
	}

	int back() {
		if (s_idx <= e_idx) {
			return arr[e_idx];
		}
		else {
			return -1;
		}
	}
};

int main() {
	int n;
	scanf("%d", &n);

	char cmd[10];
	Queue q;
	for (int i = 0; i < n; i++) {
		scanf("%s", cmd);

		if (strcmp(cmd, "push") == 0) {
			int num;
			scanf("%d\n", &num);

			q.push(num);
		}
		else if (strcmp(cmd, "pop") == 0) {
			printf("%d\n", q.pop());
		}
		else if (strcmp(cmd, "size") == 0) {
			printf("%d\n", q.size());
		}
		else if (strcmp(cmd, "empty") == 0) {
			printf("%d\n", q.empty());
		}
		else if (strcmp(cmd, "front") == 0) {
			printf("%d\n", q.front());
		}
		else if (strcmp(cmd, "back") == 0) {
			printf("%d\n", q.back());
		}
	}
	return 0;
}