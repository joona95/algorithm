#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

int w[11];
int k[11];

int main() {
	for (int i = 0; i < 10; i++) {
		scanf("%d", &w[i]);
	}
	for (int i = 0; i < 10; i++) {
		scanf("%d", &k[i]);
	}

	sort(w, w + 10, greater<>());
	sort(k, k + 10, greater<>());

	int wsum = w[0] + w[1] + w[2];
	int ksum = k[0] + k[1] + k[2];

	printf("%d %d", wsum, ksum);

	return 0;
}