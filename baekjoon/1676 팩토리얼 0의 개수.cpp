#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	
	int arr[2] = { 0, };
	int cnt = 0;
	for (int i = n; i > 0; i--) {
		int tmp = i;
		while (tmp % 10 == 0) {
			tmp /= 10;
			cnt++;
		}
		while (tmp % 5 == 0) {
			tmp /= 5;
			arr[1]++;
		}
		while (tmp % 2 == 0) {
			tmp /= 2;
			arr[0]++;
		}
	}

	while (arr[0] != 0 && arr[1] != 0) {
		cnt++;
		arr[0]--;
		arr[1]--;
	}

	cout << cnt;

	return 0;
}

/*
2와 5의 갯수 구하기 다른 방법
	for(int i=2;i<=n;i*=2){
		arr[0]+=n/i;
	}
	for(int i=5;i<=n;i*=5){
		arr[1]+=n/i;
	}

	if(arr[0]>arr[1]) cnt=arr[1];
	else cnt=arr[0];
*/