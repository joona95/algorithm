#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		char c[51];
		scanf("%s", c);

		int length = strlen(c);

		bool end = true;
		stack<char> s;
		for (int i = 0; i < length; i++) {
			if (c[i] == '(') {
				s.push(c[i]);
			}
			else if (c[i] == ')') {
				if (!s.empty()) {
					s.pop();
				}
				else {
					end = false;
					break;
				}
			}
		}

		if (!s.empty() || end == false) {
			printf("NO\n");
		}
		else {
			printf("YES\n");
		}
	}

	return 0;
}

/*
아예 함수로 빼서 return 해주는 게 나을듯
string valid(string s) {
	int cnt = 0;
	for (int i=0; i<s.size(); i++) {
		if (s[i] == '(') {
			cnt += 1;
		} else {
			cnt -= 1;
		}
		if (cnt < 0) {
			return "NO";
		}
	}
	if (cnt == 0) {
		return "YES";
	} else {
		return "NO";
	}
}
*/