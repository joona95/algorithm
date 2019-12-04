#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<unsigned long long> v1;
vector<unsigned long long> v2;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	int n, w;
	cin >> n >> w;
	v1.push_back(1e9);
	v2.push_back(1e9);
	for (int i = 1; i <= n; i++) {
		int t, s;
		cin >> t >> s;
		if (t == 5)
			v1.push_back(s);
		else
			v2.push_back(s);
	}

	sort(v1.begin(), v1.end(), cmp);
	sort(v2.begin(), v2.end(), cmp);

	v1[0] = 0;
	v2[0] = 0;
	for (int i = 1; i < v1.size(); i++) {
		v1[i] += v1[i - 1];
	}
	for (int i = 1; i < v2.size(); i++) {
		v2[i] += v2[i - 1];
	}

	
	unsigned long long max = 0;
	int x = w / 5;
	for (int i = x; i >= 0; i--) {
		int y = (w - (5 * i))/3;
		unsigned long long  total = 0;
		if (i < v1.size()-1)
			total += v1[i];
		else
			total += v1[v1.size()-1];

		if (y < v2.size()-1)
			total += v2[y];
		else
			total += v2[v2.size()-1];
	
	
		if (max < total) {
			max = total;
		}
	}

	cout << max;
	

	return 0;
}