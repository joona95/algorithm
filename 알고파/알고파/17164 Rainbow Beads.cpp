#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

using namespace std;

char beads[250001];


int main() {
	int n;
	scanf("%d\n", &n);

	for (int i = 0; i < n; i++) {
		scanf("%c", &beads[i]);
	}

	int max = 1;
	int s = 0, e = 0;
	while (e<n-1) {

		//printf("%d %c %c\n", e, beads[e], beads[e+1]);
		if (beads[e] == beads[e + 1]) {
			s = e + 1;
			e = s;
		}
		else {
			if (beads[e] == 'R') {
				if (beads[e + 1] == 'V') {
					s = e + 1;
					e = s;
				}
				else {
					e++;
				}
			}
			else if (beads[e] == 'V') {
				if (beads[e + 1] == 'R' || beads[e + 1] == 'B') {
					s = e + 1;
					e = s;
				}
				else {
					e++;
				}
			}
			else {//'B'
				if (beads[e + 1] == 'V') {
					s = e + 1;
					e = s;
				}
				else {
					e++;
				}
			}
		}

		if (max < e - s + 1) {
			max = e - s + 1;
		}
	}
	
	
	printf("%d", max);

	return 0;
}

/*
while �ϳ����� �ذ� ������ġ�� ����.
���� �ϳ��� ���� �� max���� 1�� ����.
*/

/*
�������� �ð��ʰ�

int max = 0;
	for (int i = 0; i < n; i++) {
		int s = i, e = i;
		while (s <= e) {
			if (e == n - 1) {
				break;
			}

			//printf("%d %c %c\n", e, beads[e], beads[e+1]);
			if (beads[e] == beads[e+1]) {
				break;

			}
			else {
				if (beads[e] == 'R') {
					if (beads[e + 1] == 'V') {
						break;
					}
					else {
						e++;
					}
				}
				else if (beads[e] == 'V') {
					if (beads[e + 1] == 'R' || beads[e + 1] == 'B') {
						break;
					}
					else {
						e++;
					}
				}
				else {//'B'
					if (beads[e + 1] == 'V') {
						break;
					}
					else {
						e++;
					}
				}
			}
		}
*/