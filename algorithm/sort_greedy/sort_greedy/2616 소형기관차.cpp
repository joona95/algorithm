#include <iostream>
#include <algorithm>
using namespace std;

int arr[50005];
int dp[4][50005];
int main() {
	int n, m;
	cin >> n;//전체 객차 수
	for (int i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;
		arr[i] = arr[i - 1] + tmp;//객차마다 손님 누적합!! -> [i] - [i-m] 으로 소형차가 끄는 객차의 승객수 쉽게 구할 수 있음
	}
	cin >> m;//소형기관차당 끌 수 있는 최대 객차 수

	for (int i = 1; i <= 3; i++) { //첫번째 소형차 i=1, 두번째 소형차 i=2, 세번째 소형차 i=3
		for (int j = i * m; j <= n; j++) {
			dp[i][j] = max(dp[i][j - 1], arr[j] - arr[j - m] + dp[i - 1][j - m]);
			/*첫번째 소형차가 끌 수 있는 객차의 최대 승객수 각각 j번째까지
			그 이후에 두번째 소형차는 첫번째 소형차가 끈 j 이후부터 , 세번째는 두번째가 끈 이후부터*/
		}
	}

	cout << dp[3][n];

	return 0;
}

/*런타임 에러 왜 나는거지?
한 소형 열차당 끌 수 있는 객차 최대 수
그것보다 작을 수도 있음 고려해야함

그렇지만 계속 런타임 에러가 뜬다.

=> 런타임에러에서 수정돼서 시간초과
*/

