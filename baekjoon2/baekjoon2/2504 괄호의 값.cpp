#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <stack>
#include <cstring>

using namespace std;

int main() {
	int answer = 0;
	char str[31];
	scanf("%s", str);

	stack<char> s;
	int len = strlen(str);
	int temp = 1;
	for (int i = 0; i < len;i++) {
		if (str[i]=='(') {
			temp *= 2;
			s.push('(');
		}
		else if (str[i] == '[') {
			temp *= 3;
			s.push('[');
		}
		else if (str[i] == ')') {
			if (s.empty() || s.top() != '(') {
				answer = 0;
				break;
			}
			if (str[i - 1] == '(') {
				answer += temp;
				temp /= 2;
				s.pop();
			}
			else {
				temp /= 2;
				s.pop();
			}
		}
		else if (str[i] == ']') {
			if (s.empty() || s.top() != '[') {
				answer = 0;
				break;
			}
			if (str[i - 1] == '[') {
				answer += temp;
				temp /= 3;
				s.pop();
			}
			else {
				temp /= 3;
				s.pop();
			}
		}
	}

	if (!s.empty()) {
		answer = 0;
	}

	printf("%d", answer);

	return 0;
}

/*
(()[[]])([])

answer=22+6
temp=1

[][]((])

*/