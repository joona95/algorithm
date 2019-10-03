#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int *a = new int[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int num;
		scanf("%d", &num);
		
		int l = 0, r = n - 1;
		
		bool find = false;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (a[mid] > num) {
				r = mid - 1;
			}
			else if (a[mid] < num) {
				l = mid + 1;
			}
			else if (a[mid] == num) {
				find = true;
				break;
			}
		}

		if (find == false) {
			printf("0\n");
		}
		else {
			printf("1\n");
		}
	}
	return 0;
}

//cin, cout 시간초과