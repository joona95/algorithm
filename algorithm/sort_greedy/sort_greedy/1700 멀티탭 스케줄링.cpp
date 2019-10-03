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
	//���Ŀ� �� �ѹ��� ���������� �� ���ų� ���� ���߿� ���� �� ����
	int n, k;
	cin >> n >> k;
	int *plug = new int[n];
	vector<int> v;
	int total[105] = { 0, };
	queue<int> idx[105];
	//last idx�����ϴ°� �ƴ϶� ��ü�� ����ϴ� idx �����س��� ���ķ� ���� ���߿��� ���� ���߿� ����
	/*
	�ݷ�:
	3 14
	1 4 3 2 5 4 3 2 5 3 4 2 3 4
	��: 4
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
�̸� �� ���� ���⸸�ϰ� �����ϸ� ���� ����
�ݷ�:
2 11
1 2 3 4 5 1 1 1 2 2 2
��:4  ���:3
*/

/*�Է¼�������ؾ��� �� ��������*/

