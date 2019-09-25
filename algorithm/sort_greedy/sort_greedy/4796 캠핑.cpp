#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> l, p, v;
	int a, b, c, n=0;
	cin >>  a >> b >> c;
	while (!(a==0&&b==0&&c==0)) {
		l.push_back(a);
		p.push_back(b);
		v.push_back(c);
		n++;
		cin >> a >> b >> c;
	}

	//반례: 2 8 20
	//마지막으로 남은 길이가 중요
	for (int i = 0; i < n; i++) {
		int result;
		if(v[i]%p[i]>l[i])
			result = (v[i] / p[i])*l[i] + l[i];
		else
			result = (v[i] / p[i])*l[i] + v[i]%p[i];
		cout << "Case " << i+1 << ": " << result << "\n";
	}
	
	return 0;
}