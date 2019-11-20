#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> bottom;
vector<int> top;
int b[500001];
int t[500001];
int main() {
	int n, h;
	cin >> n >> h;

	for (int i = 0; i < n/2; i++) {
		int num;
		cin >> num;
		bottom.push_back(num);
		b[num]++;
		cin >> num;
		top.push_back(num);
		t[num]++;
	}

	sort(bottom.begin(), bottom.end());
	sort(top.begin(), top.end());

	for (int i = h-1; i > 0; i--) {
		b[i] = b[i + 1] + b[i];
		t[i] = t[i + 1] + t[i];
	}

	int min = 1e9, cnt=0;
	for (int i = 1; i <= h; i++) {
		int result = b[i] + t[h - i + 1];
		if (result < min) {
			cnt = 0;
			cnt++;
			min = result;
		}
		else if (result == min) {
			cnt++;
		}
	}

	/*
	for (int i = 1; i <= h; i++) {
		cout << "b:" << b[i] << " " << "t:" << t[i] << "\n";
	}*/
	
	cout << min << " " << cnt;

	return 0;
}

/*bottom, top나눠서 생각. 최악의 경우 n*h가 되므로 */