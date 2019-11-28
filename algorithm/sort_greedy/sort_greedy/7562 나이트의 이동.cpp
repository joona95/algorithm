#include <iostream>
#include <queue>
using namespace std;

int main() {
	int num;
	cin >> num;


	for (int i = 1; i <= num; i++) {
		bool visit[305][305] = { false, };
		int cnt[305][305] = { 0, };
	
		int l, s1, s2, e1, e2;
		cin >> l;
		cin >> s1 >> s2;
		cin >> e1 >> e2;
		

		queue<pair<pair<int, int>, int>> q;
		q.push(make_pair(make_pair(s1, s2), 0));
		visit[s1][s2] = true;

		while (!q.empty() && visit[e1][e2]==0) {
			int x = q.front().first.first;
			int y = q.front().first.second;
			int n = q.front().second;
			q.pop();

			if (x - 1 >= 0 && y - 2 >= 0 && visit[x-1][y-2]==0) {
				q.push(make_pair(make_pair(x - 1, y - 2), n + 1));
				visit[x - 1][y - 2] = true;
				cnt[x-1][y-2] = n + 1;
			}
			if (x - 2 >= 0 && y - 1 >= 0 && visit[x-2][y-1] == 0) {
				q.push(make_pair(make_pair(x - 2, y - 1), n + 1));
				visit[x-2][y-1] = true;
				cnt[x - 2][y - 1] = n + 1;
			}
			if (x + 1 <l && y - 2 >= 0 && visit[x+1][y-2] == 0) {
				q.push(make_pair(make_pair(x + 1, y - 2), n + 1));
				visit[x+1][y-2] = true;
				cnt[x + 1][y - 2] = n + 1;

			}
			if (x + 2 <l && y - 1 >= 0 &&visit[x+2][y-1] == 0) {
				q.push(make_pair(make_pair(x + 2, y - 1), n + 1));
				visit[x+2][y-1] = true;
				cnt[x + 2][y - 1] = n + 1;
			}
			if (x - 1 >= 0 && y + 2 < l && visit[x-1][y+2] == 0) {
				q.push(make_pair(make_pair(x - 1, y + 2), n + 1));
				visit[x-1][y+2] = true;
				cnt[x - 1][y + 2] = n + 1;
			}
			if (x - 2 >= 0 && y + 1 < l &&visit[x-2][y+1] == 0) {
				q.push(make_pair(make_pair(x - 2, y + 1), n + 1));
				visit[x-2][y+1] = true;
				cnt[x - 2][y + 1] = n + 1;
			}
			if (x + 1 < l && y + 2 < l && visit[x+1][y+2] == 0) {
				q.push(make_pair(make_pair(x + 1, y + 2), n + 1));
				visit[x+1][y+2] = true;
				cnt[x + 1][y + 2] = n + 1;
			}
			if (x + 2 < l && y + 1 <l && visit[x+2][y+1] == 0) {
				q.push(make_pair(make_pair(x + 2, y + 1), n + 1));
				visit[x+2][y+1] = true;
				cnt[x + 2][y + 1] = n + 1;
			}
			
			
		}
		
		if(visit[e1][e2]!=0)
			cout << cnt[e1][e2]<<"\n";
	}


	return 0;
}

/*테스트케이스는 다 맞는데 틀렸습니다 뜸. 왜인지 모르겠음.
check(visit)이랑 cnt 따로 하니까 맞았다.
*/