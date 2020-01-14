#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>

int arr[10005];

class Stack {
public:
	int idx = -1;

	void push(int x) {
		arr[++idx] = x;
	}

	int pop() {
		int result;
		if (idx > -1) {
			return result = arr[idx--];
		}
		else {
			return -1;
		}
		
	}

	int size() {
		return idx + 1;
	}

	int empty() {
		if (idx > -1) {
			return 0;
		}
		else {
			return 1;
		}
	}

	int top() {
		if (idx > -1)
			return arr[idx];
		else
			return -1;
	}
};

int main() {
	int n;
	scanf("%d", &n);

	char cmd[10];
	Stack s;
	for (int i = 0; i < n; i++) {
		scanf("%s", cmd);

		if (strcmp(cmd, "push")==0) {
			int num;
			scanf("%d", &num);
			s.push(num);
		}
		else if (strcmp(cmd, "pop") == 0) {
			printf("%d\n", s.pop());
		}
		else if (strcmp(cmd, "size") == 0) {
			printf("%d\n", s.size());
		}
		else if (strcmp(cmd, "empty") == 0) {
			printf("%d\n", s.empty());
		}
		else if (strcmp(cmd, "top") == 0) {
			printf("%d\n", s.top());
		}
	}

	return 0;
}