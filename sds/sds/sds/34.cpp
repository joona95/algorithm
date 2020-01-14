#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>

using namespace std;

bool arr[10000005];
vector<int> v;

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 2; i <= n; i++) {

		if (arr[i] == true)
			continue;

		arr[i] = true;
		v.push_back(i);

		int r = i * 2;
		while (r <= n) {
			if(arr[r]==false)
				arr[r] = true;
			r += i;
		}
	}

	for (int i = 0; i < v.size(); i++) {
		while (n%v[i] == 0) {
			printf("%d\n", v[i]);
			n /= v[i];
		}
	}

	return 0;
}