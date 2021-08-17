#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

using namespace std;

int n;
int arr[15];
int op[4];
int min = 1000000001;
int max = -1000000001;

//분리하는건 좋은데 함수 안에서 함수를 또 부르니까 속도는 0ms->4ms로 느려지긴 함..
int caculator(int operation, int num1, int num2) {
	if (operation == 0) {
		return num1 + num2;
	}
	if (operation == 1) {
		return num1 - num2;
	}
	if (operation == 2) {
		return num1 * num2;
	}
	if (operation == 3) {
		return num1 / num2;
	}
}

 void dfs(int idx, int result) {
	 if (idx == n) {
		 if (min > result) {
			 min = result;
		 }
		 if (max < result) {
			 max = result;
		 }
		 return;
	 }

	 for (int i = 0; i < 4; i++) {
		 if (op[i] != 0) {
			 op[i]--;
			 int res = caculator(i, result, arr[idx]);
			 dfs(idx + 1, res);
			 op[i]++;
		 }
	 }
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	scanf("%d %d %d %d", &op[0], &op[1], &op[2], &op[3]);

	dfs(1, arr[0]);

	printf("%d\n%d\n", max, min);

	return 0;
}

/*
void solution(int idx, int result, int plus, int subtract, int multiply, int divide) {
	 if (idx == n) {
		 if (min > result) {
			 min = result;
		 }
		 if (max < result) {
			 max = result;
		 }
		 return;
	 }

	if (plus != 0) {
		solution(idx + 1, result + arr[idx], plus - 1, subtract, multiply, divide);
	}
	if (subtract != 0) {
		solution(idx + 1, result - arr[idx], plus, subtract - 1, multiply, divide);
	}
	if (multiply != 0) {
		solution(idx + 1, result * arr[idx], plus, subtract, multiply - 1, divide);
	}
	if (divide != 0) {
		solution(idx + 1, result / arr[idx], plus, subtract, multiply, divide - 1);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	scanf("%d %d %d %d", &op[0], &op[1], &op[2], &op[3]);

	solution(1, arr[0]);

	printf("%d\n%d\n", max, min);

	return 0;
}
*/