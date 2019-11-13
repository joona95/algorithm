#include <iostream>
using namespace std;
int arr[10005];
int main() {
	int n, m;
	int min=0, max=0, total=0, result=0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		total += arr[i];
		if(arr[i] > max) {
			max = arr[i];
		}
	}
	cin >> m;

	if (total < m) {
		result = max;
	}
	else {
		while (min <= max) {
			total = 0;
			int mid = (min + max) / 2;
			for (int i = 1; i <= n; i++) {
				if (arr[i] < mid) {
					total += arr[i];
				}
				else {
					total += mid;
				}
			}

			if (total > m) {
				max = mid-1;
			}
			else {
				min = mid+1;
				result = mid;
			}
		}
	}

	cout << result;

	return 0;
}

/*최솟값을 주어진 수의 min값으로 설정하지 않고 0으로 설정해야함.*/