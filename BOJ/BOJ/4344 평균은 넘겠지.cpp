#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

using namespace std;

int student[1001];

int main() {
	int c;
	scanf("%d", &c);
	for (int i = 0; i < c; i++) {
		int n;
		scanf("%d", &n);
		int sum = 0;
		for (int j = 0; j < n; j++) {
			scanf("%d", &student[j]);
			sum += student[j];
		}
		int average = sum / n;
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (student[j] > average) {
				cnt++;
			}
		}
		printf("%.3f%%\n", (double)cnt / n * 100);
	}
	return 0;
}