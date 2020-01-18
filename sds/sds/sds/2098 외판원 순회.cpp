#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

int n;
int w[20][20];
int dp[20][1<<16];

int min(int a, int b) {
	return (a > b ? b : a);
}

int tsp(int cur, int state) {

	if (state == (1 << n) - 1) {
		if (!w[cur][0])
			return 1e9;
		else
			return w[cur][0];
	}//�ٽ� ������ ���÷� ���ƿü��ִ��� Ȯ��

	if (dp[cur][state] != 1e9)
		return dp[cur][state]; //���ϸ� �ð��ʰ�

	for (int i = 0; i < n; i++) {//���� �湮�� ���� ���� �õ�
		if ((state&(1<<i))==0&&w[cur][i]!=0) {//�ش� ���ø� �湮���� �ʾҰ�����°�찡 �ƴϸ�
			dp[cur][state] = min(dp[cur][state], tsp(i, (state|1 << i)) + w[cur][i]);
		}
	}

	return dp[cur][state];
}


int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &w[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (1 << n); j++) {
			dp[i][j] = 1e9;
		}
	}

	printf("%d", tsp(0,1));

	return 0;
}


/*
n=16
d[16 , 2^16]
��Ʈ����..?

d[0, 0000..1] ������ �ʿ��� �ݾ�

�迭
�ʱⰪ
d(cur,111..1)=A(cur,0)
��ȭ��
d(current, state)+A[cur,0] ..?


��Ʈ���깮�� : Ÿ�ϸ� ���� 11726

*/

