#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>

using namespace std;

int memo[1000001];

int main() {
	int t, n, m;
	scanf("%d", &t);
	for (int j = 0; j < t; j++) {

		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &memo[i]);
		}

		sort(memo, memo + n);

		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			int num;
			scanf("%d", &num);

			int low = 0;
			int high = n - 1;

			while (low<=high) {
				int mid = (low + high) / 2;

				if (num <= memo[mid]) {
					high = mid - 1;
				}
				else {
					low = mid + 1;
				}
			}

			if (memo[low]==num) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}
		}

		//�迭 �ʱ�ȭ �ʿ�
		for (int i = 0; i < n; i++) {
			memo[i] = 0;
		}
	}

	return 0;
}


/* 
set / unordered_set

unordered_set�̳� unordered_map�� �ؽø� ����մϴ�. �̵��� ����/Ž��/������ ��� O(1)�̶�� ���� �������� ����� �׷��ٴ� ���̰�, ������ Ž���� �ҿ��ϴ� �ð��� �ؽ� Ž�� �������� �浹�� �󸶳� �߻��ϴ����� �޷��ֽ��ϴ�. ���� ���� ���� �ؽð��� ������ �ִٸ� �� �߿����� ������ ��ġ�ϴ� ���� ã�Ƴ� ������ �� ������ ������ �������� �մϴ�.

�� ������ �Է��� ������ ũ�� ������ ������ ũ���� �ؽ÷δ� ����� ���� �浹�� ���� �� ����, �ſ� ū �ؽø� �ٷ�� �� ��ü�� �ð��� ����� �ҿ��ϴ� ���� �˴ϴ�.


	int t, n, m;
	scanf("%d", &t);
	for (int j = 0; j < t; j++) {

		scanf("%d", &n);
		set<int> s;
		for (int i = 0; i < n; i++) {
			int num;
			scanf("%d", &num);
			s.insert(num);
		}


		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			int num;
			scanf("%d", &num);

			if (s.find(num) != s.end()) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}
		}
	}

	return 0;

*/