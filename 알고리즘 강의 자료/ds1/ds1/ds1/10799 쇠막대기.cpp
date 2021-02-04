#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

char c[100001];

int main() {
	scanf("%s", c);

	int length = strlen(c);
	int answer = 0;
	stack<char> s;
	for (int i = 0; i < length; i++) {
		if (c[i] == '(') {
			s.push(c[i]);
		}
		else {
			s.pop();
			if (c[i - 1] == '(') { //레이저일 때 전체 값 더하기
				answer += s.size();
			}
			else {
				answer++;
			}
		}
	}

	printf("%d", answer);

	return 0;
}

/*
레이저일 때와 아닐때 구분
레이저일 때는 stack에 쌓인 값만큼 더하고
아닐 때는 끊기기 때문에 자투리 1만 더함
*/