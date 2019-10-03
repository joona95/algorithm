#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

/*
class plug {
public:
	int name, cnt;

	plug(int _name, int _cnt) {
		name = _name;
		cnt = _cnt;
	}
};


bool operator< (plug a, plug b) {
	return a.cnt < b.cnt;
}


bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}
*/

int main() {
	//total count, last idx
	//이후에 단 한번도 사용되지않을 거 빼거나 제일 나중에 쓰일 거 빼기
	int n, k;
	cin >> n >> k;
	int *plug = new int[n];
	vector<int> v;
	int total[105] = { 0, };
	queue<int> idx[105];
	//last idx저장하는게 아니라 전체로 사용하는 idx 저장해놓고 이후로 쓰는 것중에서 제일 나중에 쓸거
	/*
	반례:
	3 14
	1 4 3 2 5 4 3 2 5 3 4 2 3 4
	답: 4
	*/
	for (int i = 1; i <= k; i++) {
		int x;
		cin >> x;
		v.push_back(x);
		total[x]++;
		idx[x].push(i);
	}
	
	
	int cnt = 0;
	int start = 0;
	for (int i = 0; i < k; i++) {
		
		if (start < n) {
			int find = 0;
			for (int j = 0; j < start; j++) {
				if (plug[j] == v[i]) {
					find = 1;
				}
			}

			if (find == 0) {
				plug[start] = v[i];
				total[v[i]]--;
				idx[v[i]].pop();
				start++;
				cout << i << ":0\n";
			}
			else {
				total[v[i]]--;
				idx[v[i]].pop();
			}
			
		}
		else { //i>=n
			int find = 0;
			for (int j = 0; j < n; j++) {
				if (plug[j] == v[i]) {
					find = 1;
					total[v[i]]--;
					idx[v[i]].pop();
					cout << i << ":1\n";
				}
			}

			if (find == 0) {
				int max = 0, l = 0;
				for (int j = 0; j < n; j++) {
					if (total[plug[j]] == 0) {
						plug[j] = v[i];
						total[v[i]]--;
						find = 1;
						cnt++;
						cout << i << ":2\n";
						break;
					}
					else {
						if (max < idx[plug[j]].front()) {
							max = idx[plug[j]].front();
							l = j;
						}
						cout << i << ":3\n";
					}
				}


				if (find == 0) {
					plug[l] = v[i];
					total[v[i]]--;
					idx[v[i]].pop();
					cnt++;
					cout << i << ":4\n";
				}
			}
		}

	}

	cout << cnt;
	
	return 0;
}

/*
미리 총 갯수 세기만하고 시작하면 문제 생김
반례:
2 11
1 2 3 4 5 1 1 1 2 2 2
답:4  출력:3
*/

/*입력순서고려해야함 또 문제생김*/

