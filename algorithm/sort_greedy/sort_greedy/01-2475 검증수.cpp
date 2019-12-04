#include <iostream>
using namespace std;
int main() {
	int arr[5];
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
	}
	
	int total = 0;
	for (int i = 0; i < 5; i++) {
		total += (arr[i] * arr[i]);
	}

	cout << total % 10;


	return 0;
}