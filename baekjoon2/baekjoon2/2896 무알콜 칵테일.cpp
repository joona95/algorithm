#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>

using namespace std;

int a, b, c, i, j, k;

int main() {
	scanf("%d %d %d %d %d %d", &a, &b, &c, &i, &j, &k);
	double divisor = min(min((double)a / i, (double)b / j), (double)c / k);
	printf("%.6f %.6f %.6f", a - i * divisor, b - j * divisor, c - k * divisor);
	return 0;
}