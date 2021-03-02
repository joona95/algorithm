#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#define MAX 100000

using namespace std;

int a[100001];
int b[100001];

int main() {
	for (int i = 0; i < MAX; i++) {
		scanf("%1d", &a[i]);
	}
	for (int i = 0; i < MAX; i++) {
		scanf("%1d", &b[i]);
	}

	//A&B
	for (int i = 0; i < MAX; i++) {
		if (a[i] == 1 && b[i] == 1)
			printf("1");
		else
			printf("0");
	}
	printf("\n");

	//A|B
	for (int i = 0; i < MAX; i++) {
		if (a[i] == 0 && b[i] == 0)
			printf("0");
		else
			printf("1");
	}
	printf("\n");

	//A^B
	for (int i = 0; i < MAX; i++) {
		if ((a[i] == 0 && b[i] == 1) || (a[i] == 1 && b[i] == 0))
			printf("1");
		else
			printf("0");
	}
	printf("\n");
	
	//~A
	for (int i = 0; i < MAX; i++) {
		if (a[i] == 0)
			printf("1");
		else
			printf("0");
	}
	printf("\n");

	//~B
	for (int i = 0; i < MAX; i++) {
		if (b[i] == 0)
			printf("1");
		else
			printf("0");
	}
	printf("\n");

	return 0;
}