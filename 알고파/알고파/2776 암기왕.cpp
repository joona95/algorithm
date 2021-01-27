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

		//배열 초기화 필요
		for (int i = 0; i < n; i++) {
			memo[i] = 0;
		}
	}

	return 0;
}


/* 
set / unordered_set

unordered_set이나 unordered_map은 해시를 사용합니다. 이들의 삽입/탐색/삭제가 모두 O(1)이라는 것은 어디까지나 평균이 그렇다는 것이고, 실제로 탐색이 소요하는 시간은 해시 탐색 과정에서 충돌이 얼마나 발생하는지에 달려있습니다. 여러 수가 같은 해시값을 가지고 있다면 그 중에서도 실제로 일치하는 값을 찾아낼 때까지 그 수들을 모조리 뒤져봐야 합니다.

이 문제는 입력이 굉장히 크기 때문에 웬만한 크기의 해시로는 상당한 양의 충돌을 피할 수 없고, 매우 큰 해시를 다루는 것 자체가 시간을 상당히 소요하는 일이 됩니다.


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