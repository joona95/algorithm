#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
char arr[10];
//int cnt[10];
int ans[3];
int main() {
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 10; i++) {
			arr[i] = 0;
		}

		scanf("%s", arr);

		int max = 0;
		int n = 0, cnt=0;
		for (int i = 0; i < 8; i++) {
			int x = arr[i];

			//printf("%d %d\n", n, x);
			if (n != x) {
				n = x;
				cnt = 1;
				//cnt[n] = 1;
			}
			else {
				cnt++;
			}

			if (max < cnt)
				max = cnt;
			//printf("%d ", cnt);
		}
		//printf("\n");
		
		ans[j] = max;
	}

	for (int i = 0; i < 3; i++) {
		printf("%d\n", ans[i]);
	}
	
	return 0;
}

/*
�� ���� ���ӵǴ� �ִ� �� ���Ѵ����� max�ΰ� ���ϸ� Ʋ����
�� ! 17771771�̸� 3�� 2�� ���ؼ� ����..������..��...
*/