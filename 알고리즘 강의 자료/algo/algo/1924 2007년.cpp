#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

using namespace std;

int main() {
	int m, d;
	scanf("%d %d", &m, &d);

	int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; //이렇게 하는 게 더 쉬움

	int day = 0;
	for (int i = 0; i < m - 1; i++) {
		day += month[i];
	}

	day += d;

	switch (day % 7) {
	case 1:
		printf("MON\n");
		break;
	case 2:
		printf("TUE\n");
		break;
	case 3:
		printf("WED\n");
		break;
	case 4:
		printf("THU\n");
		break;
	case 5:
		printf("FRI\n");
		break;
	case 6:
		printf("SAT\n");
		break;
	case 0:
		printf("SUN\n");
		break;
	}


	return 0;
}