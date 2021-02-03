#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

string dp[251];
char c[1001];

string add(string a, string b) {
	const char* c1 = a.c_str();
	const char* c2 = b.c_str();

	int length1 = a.length()-1;
	int length2 = b.length()-1;

	for (int i = 0; i < 1001; i++) {
		c[i] = 0;
	}

	int idx = 0;
	while (length1 >= 0 && length2 >= 0) {
		int n1 = c1[length1] - '0';
		int n2 = c2[length2] - '0';
		printf("%d %d\n", n1, n2);

		int n=0;
		if (c[idx] != 0) {
			n = c[idx] - '0';
		}
		c[idx] = ((n + n1 + n2) % 10) + '0';
		n = 0;
		if (c[idx+1] != 0) {
			n = c[idx+1] - '0';
		}
		c[idx + 1] = ((n+n1 + n2) / 10) + '0';
		//printf("%c %c\n", c[idx], c[idx + 1]);

		length1--;
		length2--;
		idx++;
	}

	string result(c);

	reverse(result.begin(), result.end());

	return result;

}

int main() {
	int n;
	while (scanf("%d", &n)!=EOF) {
		dp[1] = "1";
		dp[2] = "3";

		for (int i = 3; i <= n; i++) {
			dp[i] = add(dp[i - 1], add(dp[i - 2], dp[i - 2]));
		}

		printf("%s\n", dp[n].c_str());
	}

	return 0;
}

/*
long long으로도 범위 커버가 안돼서 string 변환 필요
*/