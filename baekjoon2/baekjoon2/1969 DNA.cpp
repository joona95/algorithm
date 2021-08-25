#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

int n, m;
string dna[1001];

void solve() {
	string str = "";
	int answer = 0;
	for (int i = 0; i < m; i++) {
		int arr[26] = { 0, };
		for (int j = 0; j < n; j++) {
			arr[dna[j].at(i) - 'A']++;
		}
		int maxPosition = 0;
		for (int j = 0; j < 26; j++) {
			if (arr[maxPosition] < arr[j]) {
				maxPosition = j;
			}
		}
		str += ('A' + maxPosition);
		answer += (n - arr[maxPosition]);
	}
	cout << str << "\n" << answer << "\n";
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> dna[i];
	}
	solve();
	return 0;
}

/*
5 8
TATGATAC
TAAGCTAC
AAAGATCC
TGAGATAC
TAAGATGT

*/