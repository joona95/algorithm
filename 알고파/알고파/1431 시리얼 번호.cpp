#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) {
	if (a.length() != b.length()) {
		return a.length() < b.length();
	}
	else {
		int asum = 0;
		int bsum = 0;
		char c1[51];
		char c2[51];
		strcpy(c1, a.c_str());
		strcpy(c2, b.c_str());
		int length = a.length();
		for (int i = 0; i < length; i++) {
			if (0 <= (c1[i] - 48) && (c1[i] - 48) <= 9) {
				asum += (c1[i] - 48);
			}

			if (0 <= (c2[i] - 48) && (c2[i] - 48) <= 9) {
				bsum += (c2[i] - 48);
			}
		}
		
		if (asum != bsum) {
			return asum < bsum;
		}
		else {
			if (a.compare(b) <= 0)
				return true;
			else
				return false;
		}
	}
}

int main() {
	int n;
	cin >> n;

	vector<string> v;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < n; i++) {
		cout << v[i] << "\n";
	}

	return 0;
}