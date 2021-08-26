#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int arr[105];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}


	int cnt = 0;
	for (int i = 0; i < n; i++) {
		bool b = false;
		for (int j = 2; j < arr[i]; j++) {
			if (arr[i] % j == 0) {
				b = true;
				break;
			}
		}

		if (arr[i]!= 1 && b == false) {
			cout << arr[i] << endl;
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}