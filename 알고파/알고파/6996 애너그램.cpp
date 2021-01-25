#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int c;
	cin >> c;

	for (int i = 0; i < c; i++) {
		string a, b;
		cin >> a >> b;

		char c1[100], c2[100];
		strcpy(c1, a.c_str());
		strcpy(c2, b.c_str());

		sort(c1, c1 + a.length());
		sort(c2, c2 + b.length());

		if (a.length() != b.length()) {
			cout << a << " & " << b << " are NOT anagrams.\n";
		}
		else {
			bool find = false;
			for (int j = 0; j < a.length(); j++) {
				if (c1[j] != c2[j]) {
					find = true;
					break;
				}
			}

			if (find == true) {
				cout << a << " & " << b << " are NOT anagrams.\n";
			}
			else {
				cout << a << " & " << b << " are anagrams.\n";
			}

		}

		
	}

	return 0;
}