#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n;
pair<int, string> girls[51];
int ohminsikLOVE[4] = { 0, };
int girlLOVE[4] = { 0, };

void checkLOVE(string name, int* arrLOVE) {
	for (int i = 0; i < name.length(); i++) {
		switch (name.at(i)) {
		case 'L':
			arrLOVE[0]++;
			break;
		case 'O':
			arrLOVE[1]++;
			break;
		case 'V':
			arrLOVE[2]++;
			break;
		case 'E':
			arrLOVE[3]++;
			break;
		}
	}
}

bool compare(pair<int, string> girl1, pair<int, string> girl2) {
	if (girl1.first != girl2.first) {
		return girl1.first > girl2.first;
	}
	else {
		return girl1.second < girl2.second;
	}
}

int main() {
	string ohminsik;
	cin >> ohminsik;
	checkLOVE(ohminsik, ohminsikLOVE);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> girls[i].second;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			girlLOVE[j] = 0;
		}
		checkLOVE(girls[i].second, girlLOVE);

		int result = ((ohminsikLOVE[0] +girlLOVE[0] + ohminsikLOVE[1]+ girlLOVE[1])
			*(ohminsikLOVE[0]+girlLOVE[0] + ohminsikLOVE[2]+ girlLOVE[2])
			*(ohminsikLOVE[0]+girlLOVE[0] + ohminsikLOVE[3]+ girlLOVE[3])
			*(ohminsikLOVE[1]+girlLOVE[1] + ohminsikLOVE[2]+ girlLOVE[2])
			*(ohminsikLOVE[1]+girlLOVE[1] + ohminsikLOVE[3]+ girlLOVE[3])
			*(ohminsikLOVE[2]+girlLOVE[2] + ohminsikLOVE[3]+ girlLOVE[3])) % 100;
		girls[i].first = result;
	}

	sort(girls, girls + n, compare);

	cout << girls[0].second<<"\n";

	return 0;
}