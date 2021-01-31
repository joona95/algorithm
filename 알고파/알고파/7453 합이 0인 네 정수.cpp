#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int a[4001], b[4001], c[4001], d[4001];

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
	}

	vector<long long> ab, cd;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ab.push_back((long long)a[i] + (long long)b[j]);
			cd.push_back((long long)c[i] + (long long)d[j]);
		}
	}

	sort(ab.begin(), ab.end());
	sort(cd.begin(), cd.end());

	long long answer = 0;
	
	for (int i = 0; i < ab.size(); i++) {
		long long low = 0;
		long long high = cd.size();

		while (low < high) {
			long long mid = (low + high) / 2;

			if (ab[i] + cd[mid] < 0) {
				low = mid + 1;
			}
			else {
				high = mid; //���� �� ���� �� ū�� �� ���� ���� ���� ���Ͽ�
			}
		}
		long long lower = high;

		low = 0;
		high = cd.size();
		while (low < high) {
			long long mid = (low + high) / 2;
			if (ab[i] + cd[mid] <= 0) {
				low = mid + 1;
			}
			else{
				high = mid;
			}
		}
		long long upper = high;

		answer += (upper - lower);
		
		//printf("%lld %lld %lld\n", lower, upper, answer);
	}

	printf("%lld", answer);

	return 0;
}
/*
�ݷ�
2
0 0 0 0
0 0 0 0
��:16

upper bound, lower bound ã�ƾ���
*/

/*
lower_bound, upper_bound �Լ� Ȱ��

for (int i = 0; i < ab.size(); i++) {
		long long lower = lower_bound(cd.begin(), cd.end(), -ab[i]) - cd.begin();
		long long upper = upper_bound(cd.begin(), cd.end(), -ab[i]) - cd.begin();

		answer += (upper - lower);
		//printf("%lld %lld %lld\n", lower, upper, answer);
	}
*/

/*
�翬�� �̰� �ð��ʰ��ϵ� n^4 �ϱ�
int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
	}

	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				for (int l = 0; l < n; l++) {
					if (a[i] + b[j] + c[k] + d[l] == 0) {
						answer++;
					}
				}
			}
		}
	}

	printf("%d", answer);

	return 0;
}
*/

