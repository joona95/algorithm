#include <iostream>
using namespace std;

int arr[305];
int tmp[305];
int cnt[305];
int main() {
	int n, m;
	cin >> n >> m;
	int min = 1, max = 3000, total=0;
	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		arr[i] = arr[i - 1] + t;
		total += t;
	}

	if (total < max) {
		max = total;
	}

	while (min <= max) {
		int mid = (min + max) / 2;
		int idx = 0, totalCnt=0;
		//cout << min << " " << max << " " << mid << "\n";
		int j;
		for (j = 1; j <= m && totalCnt<n; j++) {
			int count = 0;
			for (int i = idx+1; i <= n; i++) {
				
				if (mid < arr[i] - arr[idx]) {
					idx = i - 1;
					break;
				}
				else {
					count++;
				}
				//cout << i << ":" << arr[i] << "\n";
			}
			//cout << "count:" << count << "\n";
			tmp[j] = count;
			totalCnt += count;
		}

		if (totalCnt == n) {
			for (int i = 1; i <= m; i++)
				cnt[i] = tmp[i];
		}

		if (j-1 < m) {
			int num = j;
			for (int i = j-1; i > 0; i--) {
				while (cnt[i] > 1&& num<=m) {
					cnt[i]--;
					cnt[num]=1;
					num++;
				}
			}
		}

		if (totalCnt < n) {
			min = mid + 1;
		}
		else {
			max = mid - 1;
		}

		/*
		cout << "cnt\n";
		for (int i = 1; i <= m; i++) {
			cout << cnt[i] << " ";
		}
		cout << "\n";*/
	}

	int result = 0;
	int idx = 0;
	for (int i = 1; i <= m; i++) {
		idx += cnt[i];
		if (result < arr[idx] - arr[idx - cnt[i]]) {
			result = arr[idx] - arr[idx - cnt[i]];
		}
	}
	cout << result << "\n";
	for (int i = 1; i <= m; i++) {
		cout << cnt[i] << " ";
	}

	return 0;
}

/*
반례1)
1 1 
1
=>(min<max)에서 (min<=max)로 변경

반례2)
9 6
1 1 1 1 1 1 1 1 1 
답:
2
2 2 2 1 1 1
출력:
2
2 2 2 2 1 //1(이전에저장된값)
=> 일단 처음에 j<=m때문에 반복되던걸 고치기 위해 totalCnt<n 조건 추가
=> 고민중.
1) 그룹이 m보다 더 많이 생기는 경우
2) 그룹이 m보다 적게 생기는 경우 ★!! => 갯수1이상인 집합에서 하나빼서 주기
3) 그룹이 m만큼 생기는 경우


*/