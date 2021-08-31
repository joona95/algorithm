#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string s, p;

//KMP 알고리즘 : O(N+M)
vector<int> getPi(string p) {
	int length = p.length();
	vector<int> pi(length, 0);
	int j = 0;
	for (int i = 1; i < length; i++) {
		while (j > 0 && p[i] != p[j]) {
			j = pi[j - 1];
		}
		if (p[i] == p[j]) {
			pi[i] = ++j;
		}
	}
	return pi;
}
/*
ABABABAC
00123450
*/

bool kmp(string s, string p) {
	vector<int> pi = getPi(p);
	int sLength = s.length();
	int pLength = p.length();
	int j = 0;
	for (int i = 0; i < sLength; i++) {
		while (j > 0 && s[i] != p[j]) {
			j = pi[j - 1];
		}
		if (s[i] == p[j]) {
			if (j == pLength - 1) {
				return 1;
			}
			j++;
		}
	}
	return 0;
}

int main() {
	cin >> s >> p;
	printf("%d", kmp(s, p));
	return 0;
}

/*
//함수 쓰니까 시간초과!
int main() {
	cin >> s >> p;
	if (s.find(p) != string::npos) {
		printf("1");
		return 0;
	}
	printf("0");
	return 0;
}
*/