#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
bool cmp(int a, int b) {
	return a > b;
}*/

int main() {
	int n;
	cin >> n;
	
	vector<int> v;

	for (int i = 0; i < n; i++) {
		int w;
		cin >> w;
		v.push_back(w);
	}

	sort(v.begin(), v.end());
	
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (sum < v[i] - 1) {
			break;
		}
		
		sum += v[i];
	}

	cout << sum + 1;
	
	return 0;
}

/*������ �� ������ �̿�
i-1������ ������ < i��°����-1 �̸� �� ������ ��� ���� ���� �� ����
1 1 2 3 6 7 30
��: 1 2 4 7 13 20 50
0 0 vs 0
1 1 vs 0
2 2 vs 1
3 4 vs 2
4 7 vs 5
5 13 vs 6
6 20 vs 29
   
���ذ� ���� �� �Ȱ�. �̰� ��� ��������?

*/