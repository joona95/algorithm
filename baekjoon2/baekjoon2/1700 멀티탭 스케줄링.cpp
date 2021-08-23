#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

using namespace std;

#define MAX 101
int n, k;
int schedule[MAX], multitab[MAX];

bool checkNumberExist(int num) {
	for (int i = 0; i < n; i++) {
		if (multitab[i] == num) {
			return true;
		}
	}
	return false;
}

int findMaxUseMultitab(int idx) {
	int maxUseMultitab = 0;
	int maxUsePosition = -1;
	for (int i = 0; i < n; i++) {
		bool flag = false;
		for (int j = idx; j < k; j++) {
			if ((multitab[i] == schedule[j])) {
				if (maxUsePosition < j) {
					maxUseMultitab = i;
					maxUsePosition = j;
				}
				flag = true;
				break;
			}
		}
		if (!flag) {
			maxUseMultitab = i;
			maxUsePosition = 101;
		}
	}
	return maxUseMultitab;
}

int solve() {
	int answer = 0;
	int size = 0;
	for (int i = 0; i < k; i++) {
		if (checkNumberExist(schedule[i])) {
			continue;
		}
		if (size < n) {
			multitab[size] = schedule[i];
			size++;
			continue;
		}
		int maxUseMultitab = findMaxUseMultitab(i);
		multitab[maxUseMultitab] = schedule[i];
		answer++;
		/*
		for (int j = 0; j < n; j++) {
			printf("%d ", multitab[j]);
		}
		printf("\n");*/
	}
	return answer;
}

int main() {
	scanf("%d %d\n", &n, &k);
	for (int i = 0; i < k; i++) {
		scanf("%d", &schedule[i]);
	}
	printf("%d", solve());
	return 0;
}
/*
2 3 2 3 1 2 7
0:0 /1:4 /2:5 /3:3 /4:0 /5:0 /6:0 /7:6

제일 나중에 사용될 것과 한번도 사용안될것

3 6
1 1 1 1 2 3

3 10
6 7 4 8 6 4 9 1 1 9

6 7 4 
6 8 4
9 1 4
*/