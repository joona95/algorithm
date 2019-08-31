#include <iostream>
#include <vector>
using namespace std;
int main() {
	int a, b, m;
	cin >> a >> b>>m;
	vector<int> v;
	int n;
	for (int i = 0; i < m; i++) {
		cin >> n;
		v.push_back(n);
	}

	int sum = 0;
	while (!v.empty()) {
		sum += v.back();
		v.pop_back();
		for (int i = 0; i < v.size(); i++) {
			v[i] *= a;
		}
	}

	if (sum == 0) {
		cout << "0";
		return 0;
	}
	

	while (sum != 0) {
		v.push_back(sum % b);
		sum = sum / b;
	}

	for (int i = v.size() - 1; i >= 0; i--) {
		cout << v[i] << " ";
	}
	
	return 0;
}