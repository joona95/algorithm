#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int arr[100];
int main() {
	int n, k;
	cin >> n >> k;

	/*맞았음
	bool find = false;
	for (int i = 0; i < n; i++) {
		int order;
		cin >> order;
		int j;
		for (j = 0; j < k; j++) {
			if (arr[j] < order) {
				arr[j] = order;
				break;
			}
		}

		if (j == k) {
			find = true;
			break;
		}
	}*/

	
	vector<int> v;
	stack<int> *s = new stack<int>[k];
	
	for (int i = 0; i < n; i++) {
		int order;
		cin >> order;
		v.push_back(order);
	}

	
	bool find = false;
	for (int i = 0; i < n; i++) {
		int j;
		for (j = 0; j < k; j++) {
			int top;
			if (!s[j].empty())
				top = s[j].top();
			else
				top = 0;

			if (top < v[i]) {
				s[j].push(v[i]);
				break;
			}
		}

		if (j == k) {
			find = true;
			break;
		}
	}
	
	
	if (find == true) {
		cout << "NO";
	}
	else {
		cout << "YES";
	}
	
	return 0;
}

/*간단하게 구현가능*/