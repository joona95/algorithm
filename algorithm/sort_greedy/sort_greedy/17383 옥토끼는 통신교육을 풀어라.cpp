#include <iostream>
using namespace std;

int arr[100005];
int main() {
	int n;
	cin >> n;

	int min = 1, max = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (max < arr[i])
			max = arr[i];
	}

	int result = 1;
	int mid;
	while (min <= max) {
		mid = (min + max) / 2;
		//cout << "min:" << min << " " << "max:" << max << " " << "mid:" << mid << "\n";
		int sum = 0;
		for (int i = 0; i < n; i++) {
			int num = arr[i] / mid;
			if (arr[i] % mid != 0) {
				num += 1;
			}
			//cout <<arr[i]<<":"<< num << "\n";
			if (num == 1) {
				sum += 1;
			}
			else {
				sum += (num*(-1) + 2);
			}
		}
		sum -= 1;
		//cout << "sum:" << sum << "\n";

		if (sum < 0) {
			min = mid + 1;
		}
		else {
			max = mid - 1;
			result = mid;
		}
		//cout << "result:" << result << "\n";
	}

	cout << result;

	return 0;
}

/*어렵다 어려워
parametric search
1~15: 8
1~7: 4
5~6: 5

가능하면 max = mid-1 불가능하면 min=mid+1

숫자당 1칸으로 생각해서 각 일이 몇칸짜리인지 생각해보기
즉, 5일 때
3(1) 4(1) 5(1) 9(2) 10(2) 14(3) 15(3)
양쪽 한칸씩은 다른 일과 겹치게 가능

=>1칸은 +1, 2칸은 0, 3칸 -1, 4칸 -2, ... n칸 -n+2
양수이면 가능, 음수이면 불가능


1
1 
일때 문제 발생

2
2 2 일때
2가 떠야 하는데 1이뜸


*/
