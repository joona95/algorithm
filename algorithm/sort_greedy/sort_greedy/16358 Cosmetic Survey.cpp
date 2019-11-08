#include <iostream>
using namespace std;

int arr[505][505];
int d[505][505];
int s[505][505];
int main() {
	int m, n;
	cin >> m >> n;

	/*숫자가 작을 때 가장 선호, 0일때는 선호도 측정안돼서 가장 후순위이므로 무한으로 처리*/
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
	
	//d[i][j]는 i를 j보다 선호하는 사람 수
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= m; j++) {
				if (arr[k][i] < arr[k][j]) {
					d[i][j]++;
				}
			}
		}
	}

	//s[i][j] 초기화해주기  d[i][j]>d[j][i]이면 s[i][j]는 d[i][j]이고 아니면 0
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

	//s[i][j] floyd warshall 알고리즘으로 경로확인
	//S(X,Y)=max(S(X,Y), min(S(X,Z),S(Z,Y))) : 
	//S(X,Y)는 maximum preference index over all paths from X to Y
	//경로의 값이 min(d(C t, C t+1))
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

	//모든 Y에 대해 S(X,Y)>=S(Y,X)인 경우 출력
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