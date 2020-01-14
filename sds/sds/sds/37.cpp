#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

using namespace std;

int arr[100];

int main() {
	int n, k;
	scanf("%d%d", &n, &k);

	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		arr[num]++;
	}



	return 0;
}
//카드 넣기

/*
5 3
1 2 3 / 13 21

1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
2 1 13
21 1 3

3*2*1


4 2
1 1 2 / 12
3*2/2 + 1 -1 = 3
2*1 + 1*2 - 0


*/