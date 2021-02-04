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
			if (c[i - 1] == '(') { //�������� �� ��ü �� ���ϱ�
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
�������� ���� �ƴҶ� ����
�������� ���� stack�� ���� ����ŭ ���ϰ�
�ƴ� ���� ����� ������ ������ 1�� ����
*/