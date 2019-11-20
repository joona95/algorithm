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

/*��ƴ� �����
parametric search
1~15: 8
1~7: 4
5~6: 5

�����ϸ� max = mid-1 �Ұ����ϸ� min=mid+1

���ڴ� 1ĭ���� �����ؼ� �� ���� ��ĭ¥������ �����غ���
��, 5�� ��
3(1) 4(1) 5(1) 9(2) 10(2) 14(3) 15(3)
���� ��ĭ���� �ٸ� �ϰ� ��ġ�� ����

=>1ĭ�� +1, 2ĭ�� 0, 3ĭ -1, 4ĭ -2, ... nĭ -n+2
����̸� ����, �����̸� �Ұ���


1
1 
�϶� ���� �߻�

2
2 2 �϶�
2�� ���� �ϴµ� 1�̶�


*/
