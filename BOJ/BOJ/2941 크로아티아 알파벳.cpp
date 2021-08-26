#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

string word;
string alphabet[8] = { "dz=", "c=", "c-",  "d-", "lj", "nj", "s=", "z=" };
/*
int solve() {
	int answer = 0;
	int idx = 0;
	while (idx < word.length()) {
		for (int i = 0; i < 8; i++) {
			int length = alphabet[i].length();
			string tmp = word.substr(idx, length);
			if (tmp.compare(alphabet[i])==0) {
				idx += length-1;
				break;
			}
		}
		idx++;
		answer++;
	}
	return answer;
}*/

//find, replace 함수 사용
int solve() {
	for (int i = 0; i < 8; i++) {
		int idx = word.find(alphabet[i]);
		while (idx != string::npos) {
			word.replace(idx, alphabet[i].length(), "*");
			idx = word.find(alphabet[i]);
		}
	}
	return word.length();
}

int main() {
	cin >> word;
	cout << solve();
	return 0;
}

/*
둘다 메모리 2024KB 시간 0ms
시간 차이, 메모리 차이는 거의 없는 듯.
*/