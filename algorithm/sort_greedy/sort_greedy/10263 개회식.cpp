#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int h;
		cin >> h;
		v.push_back(h);
	}

	sort(v.begin(), v.end());

	/*
	int cnt = 0;
	int s = 0;
	for (int i = 0; i < n; i++) {
		//가로 세로 비교?
		if (s != v[i]) {
			if(v[i]-s<n-i){
				cnt+=v[i]-s;
				s = v[i];
				//cout << "1:" << v[i] << "\n";
			}
			else {
				cnt++;
				//cout << "2:" << v[i] << "\n";
			}
		}
	}

	cout << cnt;
	
	//틀렸음 반례 못찾겠음
	//반례 : 2 10 10 10 
	//뒤에꺼가 너무 차이 날 경우 
	*/

	/*
	int min = n;
	for (int i = 0; i < n; i++) {
		int tmp = v[i] + n - (i + 1);
		if (min > tmp)
			min = tmp;
	}
	//맞았음

	cout << min;
	*/
	
	return 0;
}

