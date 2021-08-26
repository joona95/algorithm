#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*
int main(void) {
	int N;
	int Dp[1010] = { 0, };
	int A[1010] = { 0, };
	int max = 0;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
		scanf("%d", &A[i]);

	for (int i = 1; i <= N; i++)
	{
		if (Dp[i - 1] >= 0) {
			Dp[i] = Dp[i - 1] + A[i];
		}
		else {
			Dp[i] = A[i];
		}
		if (max < Dp[i])
			max = Dp[i];
	}

	printf("%d\n", max);

	return 0;
}*/


/*
int gcd(int x, int y) {
	if (x % y != 0) {
		gcd(y, x % y);
	}
	else {
		return y;
	}
}

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		int arr[100];
		for (int j = 0; j < n; j++) {
			cin >> arr[j];
		}

		int sum = 0;
		for (int j = 0; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				if (arr[j] > arr[k]) {
					sum += gcd(arr[j], arr[k]);
				}
				else
					sum += gcd(arr[k], arr[j]);
			}
		}

		cout << sum << "\n";
	}

	return 0;
}*/

/*
int main() {
	int n, b;
	cin >> n >> b;

	stack<char> s;
	while (n / b != 0) {
		if (n % b < 10) {
			s.push(n % b + 48);
		}
		else {
			s.push(n % b + 55);
		}
		n = n / b;
	}

	if (n < 10) {
		s.push(n + 48);
	}
	else {
		s.push(n + 55);
	}

	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}

	return 0;
}
*/

/*
int main() {
	string n;
	int b;
	cin >> n >> b;

	int len = n.length();
	int sum = 0;
	for (int i = 0; i <len; i++) {
		int mul;
		if (65 <= n[i] && n[i] <= 90) {
			mul = n[i] - 55;
			for (int j = 0; j < i; j++) {
				mul = mul * b;
			}
		}
		else {
			mul = n[i] - 48;
			for (int j = 0; j < i; j++) {
				mul = mul * b;
			}
		}
		
		sum += mul;
	}

	cout << sum;

	return 0;
}*/


/*
int main() {
	string n;
	cin >> n;
	int len = n.length();
	stack<int> s;
	for (int i = len - 3; i >= 0; i = i - 3) {
		s.push((n[i] - 48)*4 + (n[i + 1] - 48) * 2 + (n[i + 2] - 48));
	}

	if (len % 3 == 2) {
		s.push((n[0] - 48) * 2 + (n[1] - 48));
	}
	else if (len % 3 == 1) {
		s.push(n[0] - 48);
	}

	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}

	return 0;
}
*/

/*
int main() {
	string n;
	cin >> n;
	int len = n.length();
	int num = n[0] - 48;
	if (num == 0) {
		cout << "0";
		return 0;
	}

	if (num >= 4) {
		cout << "1";
		num = num - 4;
		if (num >= 2) {
			cout << "1";
			num = num - 2;
		}
		else
			cout << "0";
		if (num >= 1) {
			cout << "1";
		}
		else
			cout << "0";
	}
	else if (num >= 2) {
		cout << "1";
		num = num - 2;
		if (num >= 1)
			cout << "1";
		else
			cout << "0";
	}
	else if (num >= 1)
		cout << "1";

	for (int i = 1; i < len; i++) {
		int num = n[i] - 48;
		if (num >= 4) {
			cout << "1";
			num = num - 4;
		}
		else
			cout << "0";

		if (num >= 2) {
			cout << "1";
			num = num - 2;
		}
		else
			cout << "0";

		if (num >= 1)
			cout << "1";
		else
			cout << "0";
	}
	return 0;
}*/

void binary(int n) {
	if (n == -1) {
		cout << "11";
	}
	else if (n == 1) {
		cout << "1";
	}
	else {
		if (n % (-2) == -1) {
			binary((n-1)/(-2));
			cout << "1";
		}
		else {
			binary(n/(-2));
			if (n % (-2) == 0)
				cout << "0";
			else
				cout << "1";
		}
	}
}

int main() {
	int n;
	cin >> n;

	binary(n);

	return 0;
}