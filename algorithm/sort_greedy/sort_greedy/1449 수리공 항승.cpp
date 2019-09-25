#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n, l;
	cin >> n >> l;
	int *arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	int cnt = 1;
	int s = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] - s >= l) {
			s = arr[i];
			cnt++;
		}
	}
	/*
	4 3 
	1 2 3 4
	arr[i]-s<l �� �ݴ��� ��츦 ������ >= �̴�.
	*/

	cout << cnt;

	return 0;
}