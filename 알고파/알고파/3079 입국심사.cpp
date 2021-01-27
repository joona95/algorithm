#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	vector<int> v;
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	long long low = 1;
	long long high = (long long)v[n - 1] * (long long)m; //���⼭ overflow�� ��� ���°ſ���. �� ��ȯ�� ������ ��.

	while (low <= high) {
		long long mid = (low + high) / 2;

		long long cnt = 0;
		for (int i = 0; i < n; i++) {
			cnt += (mid / v[i]);
		}

		if (cnt >= m) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
		
	}

	printf("%lld", low);

	return 0;
}

/*
�ɸ��� �ð��� �������� �̺� Ž��
*/