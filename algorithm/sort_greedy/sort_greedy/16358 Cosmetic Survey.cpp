#include <iostream>
using namespace std;

int arr[505][505];
int d[505][505];
int s[505][505];
int main() {
	int m, n;
	cin >> m >> n;

	/*���ڰ� ���� �� ���� ��ȣ, 0�϶��� ��ȣ�� �����ȵż� ���� �ļ����̹Ƿ� �������� ó��*/
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int num;
			cin >> num;
			if (num == 0) 
				arr[i][j] = 1000001;
			else
				arr[i][j] = num;
		}
	}
	
	//d[i][j]�� i�� j���� ��ȣ�ϴ� ��� ��
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= m; j++) {
				if (arr[k][i] < arr[k][j]) {
					d[i][j]++;
				}
			}
		}
	}

	//s[i][j] �ʱ�ȭ���ֱ�  d[i][j]>d[j][i]�̸� s[i][j]�� d[i][j]�̰� �ƴϸ� 0
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			if (d[i][j] > d[j][i]) {
				s[i][j] = d[i][j];
			}
			else {
				s[i][j] = 0;
			}
		}
	}

	//s[i][j] floyd warshall �˰������� ���Ȯ��
	//S(X,Y)=max(S(X,Y), min(S(X,Z),S(Z,Y))) : 
	//S(X,Y)�� maximum preference index over all paths from X to Y
	//����� ���� min(d(C t, C t+1))
	for (int k = 1; k <= m; k++) {
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= m; j++) {
				if (s[i][k] > s[k][j]) {
					if (s[i][j] < s[k][j]) {
						s[i][j] = s[k][j];
					}
				}
				else {
					if (s[i][j] < s[i][k]) {
						s[i][j] = s[i][k];
					}

				}
			}
		}
	}

	//��� Y�� ���� S(X,Y)>=S(Y,X)�� ��� ���
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			if (s[i][j] < s[j][i]) {
				break;
			}
			if (j == m) {
				cout << i << " ";
			}
		}
	}

	/*
	cout << "*\n";
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			cout << d[i][j] << " ";
		}
		cout << "\n";
	}

	cout << "*\n";

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			cout << s[i][j] << " ";
		}
		cout << "\n";
	}
	*/

	return 0;
}