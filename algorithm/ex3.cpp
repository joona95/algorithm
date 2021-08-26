#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

class Base {
public : 
	int bPublic;
protected:
	int bProtected;
private:
	int bPrivate;
};

class Derived : private Base {
public :
	int dPublic;
	
	void dFunc() {
		bPublic = 1;
		bProtected = 2;
		//bPrivate = 3;
		dPublic = 4;
		dPrivate = 5;
	}

private:
	int dPrivate;
};

int max(int* sum, int s,int e) {
	int m = 0, idx=0;
	for (int j = s; j <= e; j++) {
		if (m < sum[j]) {
			m = sum[j];
			idx = j;
		}
	}
	return idx;
}

void heapify(int* arr, int n, int i) {
	int p = i;
	int l = i * 2 + 1;
	int r = i * 2 + 2;

	if (l<n && arr[p]<arr[l]) {
		p = l;
	}

	if (r<n && arr[p]<arr[r]) {
		p = r;
	}
	
	if (i != p) {
		int tmp = arr[p];
		arr[p] = arr[i];
		arr[i] = tmp;
		heapify(arr, n, p);
	}

	for (int i = 0; i < 5; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void hSort(int* arr, int n) {
	int l = n;
	for (int i = l / 2 - 1; i >= 0; i--) {
		heapify(arr, l, i);
	}

	for (int i = l - 1; i > 0; i--) {
		int tmp = arr[0];
		arr[0] = arr[i];
		arr[i] = tmp;
		heapify(arr, i, 0);
	}
}

int cnt = 0;
void Hanoi(int n, char from, char by, char to) {
	if (n == 1) {
		printf("%d : %c->%c\n", n, from, by);
		printf("%d : %c->%c\n", n, by, to);
		cnt += 2;
	}
	else {
		Hanoi(n - 1, from, by, to);
		printf("%d : %c->%c\n", n, from, by);
		Hanoi(n - 1, to, by, from);
		printf("%d : %c->%c\n", n, by, to);
		Hanoi(n - 1, from, by, to);
		cnt += 2;
	}
}

struct Stack {
	int stack[10000] = { 0, };
	int idx = -1;

	void push(int x) {
		stack[++idx] = x;
	}

	int pop() {
		if (idx != -1) {
			int n = stack[idx];
			idx--;
			return n;
		}
		else
			return -1;
	}

	int size() {
		return idx + 1;
	}

	int empty() {
		if (idx != -1) {
			return 0;
		}
		else {
			return 1;
		}
	}

	int top() {
		if (idx != -1) {
			return stack[idx];
		}
		else {
			return -1;
		}
	}
};

struct Queue {
	int queue[10000] = { 0, };
	int s = 0, e = -1;

	void push(int x) {
		e++;
		queue[e] = x;
	}

	int pop() {
		if (s<=e) {
			int n = s;
			s++;
			return queue[n];
		}
		else
			return -1;
	}

	int size() {
		return e - s + 1;
	}

	int empty() {
		if ( s<=e) {
			return 0;
		}
		else
			return 1;
	}

	int front() {
		if (s<=e)
			return queue[s];
		else
			return -1;
	}

	int back() {
		if (s<=e)
			return queue[e];
		else
			return -1;
	}
};

struct Deque {
	int deque[20000] = { 0, };
	int s = 10000, e = 9999;

	void push_front(int x) {
		s--;
		deque[s] = x;
	}

	void push_back(int x) {
		e++;
		deque[e] = x;
	}

	int pop_front() {
		if (s <= e) {
			s++;
			return deque[s-1];
		}
		else
			return -1;
	}

	int pop_back() {
		if (s <= e) {
			e--;
			return deque[e+1];
		}
		else
			return -1;
	}

	int size() {
		return e - s + 1;
	}

	int empty() {
		if (s <= e)
			return 0;
		else
			return 1;
	}

	int front() {
		if (s <= e)
			return deque[s];
		else {
			return -1;
		}
	}

	int back() {
		if (s <= e)
			return deque[e];
		else
			return -1;
	}

};

/*
bool compare(pair<string, pair<int, pair<int, int>>> a, pair<string, pair<int, pair<int, int>>> b) {
	if (a.second.first == b.second.first) {
		if (a.second.second.first == b.second.second.first) {
			if (a.second.second.second == b.second.second.second) {
				return a.first < b.first;
			}
			else {
				return a.second.second.second > b.second.second.second;
			}
		}
		else {
			return a.second.second.first < b.second.second.first;
		}
	}
	else {
		return a.second.first > b.second.first;
	}
}
*/

bool compare(pair<int, long long int> a, pair<int, long long int> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else {
		return a.first > b.first;
	}
}

long long d[5001];
int main() {
	/*
	int n;
	cin >> n;
	int* arr = new int[n+1];
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	int* dp = new int[n + 1];
	dp[0] = 0;
	dp[1] = arr[1];
	if (n > 1)
		dp[2] = arr[1] + arr[2];
	
	for (int i = 3; i <= n; i++) {
		if (dp[i - 2] + arr[i] > dp[i - 1])
			dp[i] = dp[i - 2] + arr[i];
		else
			dp[i] = dp[i - 1];

		if (dp[i] < arr[i] + arr[i - 1] + dp[i - 3])
			dp[i] = arr[i] + arr[i - 1] + dp[i - 3];
	}
	
	int max = 0;
	for (int i = 1; i <= n; i++) {
		cout << dp[i] << endl;
		if (max < dp[i])
			max = dp[i];
	}

	cout << max << endl;
	*/

	/*
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	hSort(arr, n);

	for (int i = 0; i < n; i++)
		cout<<arr[i];

	delete[] arr;
	*/

	/*
	int n, k;
	cin >> n >> k;
	
	cout << pow(n, k) << endl;
	*/

	/*
	int n;
	scanf("%d", &n);
	int a, b, c, d, e;
	a = n / 10000 * 10000;
	b = (n - a) / 1000 * 1000;
	c = (n - a - b) / 100 * 100;
	d = (n - a - b - c) / 10 * 10;
	e = n - a - b - c - d;
	printf("[%d]", a);
	printf("[%d]", b);
	printf("[%d]", c);
	printf("[%d]", d);
	printf("[%d]", e);
	*/

	/*
	int n;
	scanf("%d", &n);
	Hanoi(n, 'A', 'B', 'C');
	printf("%d", cnt);
	*/

	/*
	int n;
	cin >> n;
	int* arr = new int[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	int* dp = new int[n + 1];
	dp[0] = 0;

	for (int i = 1; i <= n; i++) {
		int max = 0;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && max < dp[j]) {
				max = dp[j];
			}
		}
		dp[i] = max + 1;
	}

	for (int i = 0; i <= n; i++) {
		cout << dp[i] << endl;
	}
	*/


/*
    int n;
    cin>>n;
    int *arr = new int[n+1];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    
    int *dp = new int[n+1];
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        int max = 0;
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j] && max<dp[j]){
                max = dp[j];
            }
        }
        dp[i]= max+arr[i];
    }
    
    for(int i=0;i<=n;i++){
        cout<<dp[i]<<endl;
    }
	*/

/*
    int n;
    cin>>n;
    int *arr = new int[n+1];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    
    int *dp1 = new int[n+2];
    int *dp2 = new int[n+2];
	int* r = new int[n + 2];
    dp1[0] = 0;
    dp1[n+1]=0;
    for(int i=1;i<=n;i++){
        int max = 0;
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j] && max<dp1[j]){
                max = dp1[j];
            }
        }
        dp1[i] = max+1;
    }
    
    dp2[0]=0;
    dp2[n+1]=0;
    for(int i=n;i>0;i--){
        int max = 0;

        for(int j=n+1;j>i;j--){
            if(arr[i]>arr[j] && max<dp2[j]){
                max = dp2[j];
            }
        }
		dp2[i] = max + 1;
		
		max = 0;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && max < dp1[j]) {
				max = dp1[j];
			}
		}
		r[i] = dp2[i] + max;
    }    
    
	for (int i = 1; i < n + 1; i++)
		cout << r[i] << " ";
	cout << endl;
	*/

/*
    int n;
    cin>>n;
    int *arr = new int[n+1];
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    
    int *dp = new int[n+1];
    dp[0]=0;
    dp[1]=arr[1];
    if(n>=2)
        dp[2]=arr[1]+arr[2];
    for(int i=3;i<=n;i++){
        if(dp[i-3]+arr[i-1]<dp[i-2])
            dp[i]=dp[i-2]+arr[i];
        else
            dp[i]=dp[i-3]+arr[i-1]+arr[i];
    }
    
    cout<<dp[n]<<endl;    
	*/

/*
    int n;
    cin>>n;
	int dp[100001] = { 0 };
	
	for (int i = 1; i*i <= n; i++)
		dp[i * i] = 1;
		
    for(int i=2;i<=n;i++){
        int min = 10000000;
        for(int j=1;j*j<=i;j++){
			dp[j * j] = 1;
            if(dp[i-j*j]+dp[j*j]<min)
                min = dp[i-j*j]+dp[j*j];
        }
        dp[i]=min;
	}
	
	for (int i = 1; i <= n; i++) {
		cout << dp[i] << endl;
	}
	*/

/*
    int n;
    cin >> n;
    int *dp = new int[n+1];
    dp[0]=1;
    dp[1]=0;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-2]*3;
        for(int j=i-4;j>=0;j-=2){
			dp[i] += dp[j] * 2;
        }
    }
    cout<<dp[n]<<endl;
  */

	/*
	int t;
    cin>>t;
    for(int j=0;j<t;j++){
        int n;
        cin>>n;
        long long int *dp = new long long int[n+5];
        dp[1]=1;
        dp[2]=1;
        dp[3]=1;
        dp[4]=2;
        dp[5]=2;
        for(int i=6;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-5];
        }
    
        cout<<dp[n]<<endl;
    }
	*/

/*
    int n,k;
    cin >>n>>k;
    
    long long int dp[201][201]={0,};

    for(int i=0;i<=n;i++)
        dp[1][i]=1;
    
    for(int i=2;i<=k;i++){
        for(int j=0;j<=n;j++){
			for (int l = 0; l <= j; l++)
				dp[i][j] = (dp[i][j] + dp[i - 1][l]) % 1000000000;
        }
    }
       
    cout<<dp[k][n]<<endl;
  */

/*
    int arr[11][11];
    for(int i=1;i<=10;i++){
        for(int j=1;j<=10;j++){
            cin>>arr[i][j];
        }
    }
    
    int x=2,y=2;
	while(x <= 10 &&arr[x][y]!=1 && arr[x][y]!=2) {
		while (y <= 10) {
			if (arr[x][y] != 1 && arr[x][y] != 2) {
				arr[x][y] = 9;
				y++;
			}
			else {
				y--;
				break;
			}
		}
		x++;
	}
	if (arr[x][y] == 2)
		arr[x][y] = 9;
    
    for(int i=1;i<=10;i++){
        for(int j=1;j<=10;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
  */

/*
    int n;
    cin>>n;
    int *arr=new int[n+1];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    
    int *dp=new int[n+1];
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = arr[i];
		for (int j = 1; j < i; j++) {
			if (dp[i] < dp[i - j] + dp[j])
				dp[i] = dp[i - j] + dp[j];
		}

	}

	//for(int i=0;i<=n;i++)
		cout << dp[n] << endl;
		*/

/*
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> v;
    for(int i=0;i<n;i++){
        int x, y;
        scanf("%d%d", &x, &y);
        v.push_back(make_pair(x, y));
    }
    
    sort(v.begin(), v.end(), compare);
    
    for(int i=0;i<n;i++){
        printf("%d %d\n",v[i].first, v[i].second);
    }
	*/
/*
	int n;
	cin >> n;
    vector<pair<int, string>> v;
    for(int i=0;i<n;i++){
        int age;
        string name;
		cin >> age >> name;
        v.push_back(make_pair(age, name));
    }
    
    stable_sort(v.begin(), v.end());
    
    for(int i=0;i<n;i++){
		cout << v[i].first << " " << v[i].second <<"\n";
    }
	*/
  
/*
    int n;
    cin>>n;
    vector<pair<string,pair<int, pair<int, int>>>> v;
    for(int i=0;i<n;i++){
        string name;
        int k, e, m;
        cin>>name>>k>>e>>m;
        v.push_back(make_pair(name, make_pair(k, make_pair(e, m))));
    }
    
    sort(v.begin(), v.end(), compare);
    
    for(int i=0;i<n;i++){
        cout<<v[i].first<<"\n";
    }
	*/

/*
    int n;
    cin>>n;
    vector<pair<int, long long int>> v;
    bool find=false;
    for(int i=0;i<n;i++){
        long long int num;
        cin>> num;
        for(int j=0;j<v.size();j++){
            if(v[j].second==num){
                v[j].first++;
                find=true;
                break;
            }
        }

        if(find==false){
            v.push_back(make_pair(1, num));
        }
    }
    
    sort(v.begin(), v.end(), compare);
    
	for (int i = 0; i < v.size(); i++)
		cout << v[i].first << " " << v[i].second << endl;
  */

/*
    int n;
    int arr[10001]={0,};
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        int num;
        scanf("%d", &num);
        arr[num]++;
    }
    
    for(int i=0;i<10001;i++){
        if(arr[i]!=0){
            for(int j=0;j<arr[i];j++){
                printf("%d\n",i);
            }
        }
    }
	*/

/*
    int n;
	scanf("%d", &n);

	Stack s;
	
    for(int i=0;i<n;i++){
		char str[20];
		scanf("%s", str);
	
        if(strcmp(str, "push")==0){
			int num;
			scanf("%d", &num);
			s.push(num);
        }
        else if(strcmp(str, "pop")==0){
			printf("%d\n", s.pop());
        }
        else if(strcmp(str, "size")==0){
			printf("%d\n", s.size());
        }
        else if(strcmp(str, "empty")==0){
			printf("%d\n", s.empty());
        }
        else if(strcmp(str, "top")==0){
			printf("%d\n", s.top());
        }
    }
  */

/*
    int n;
    scanf("%d\n", &n);

    for(int i=0;i<n;i++){
        char c;
        stack<char> s;
		scanf("%c", &c);
        while(c!='\n'){
			
			switch (c) {
			case '(':
				s.push(c);
				printf("push: (\n");
				break;
			case ')':
				if (!s.empty() && s.top()=='(') {
					s.pop();
					printf("pop\n");
				}
				else {
					s.push(c);
					printf("push: )\n");
				}
				break;
			}

  			scanf("%c", &c);
        }
        
        if(s.empty()==1){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
	*/

/*
	int sum = 0;
	string str;
    cin>>str;
	stack<char> s;
    int l = str.length();
    for(int i=0;i<l;i++){
		if (str[i] == '(') {
			s.push(str[i]);
		}
		else if (str[i] == ')'){
			s.pop();
			if (str[i-1]=='(') {
				sum += s.size();
			}
			else {
				sum++;
			}
        }

	}

	printf("%d\n", sum);
	*/

/*
	char str[10];
	int n;
	scanf("%d\n", &n);
	Queue q;
	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		if (strcmp(str, "push")==0) {
			int num;
			scanf("%d", &num);
			q.push(num);
		}
		else if (strcmp(str, "pop") == 0) {
			printf("%d\n", q.pop());
		}
		else if (strcmp(str, "size") == 0) {
			printf("%d\n", q.size());
		}
		else if (strcmp(str, "empty") == 0) {
			printf("%d\n", q.empty());
		}
		else if (strcmp(str, "front") == 0) {
			printf("%d\n", q.front());
		}
		else if (strcmp(str, "back") == 0) {
			printf("%d\n", q.back());
		}
	}
	*/

/*
	int n;
	scanf("%d\n", &n);
	Deque dq;

	for (int i = 0; i < n; i++) {
		char str[20];
		scanf("%s", str);
		if (strcmp(str, "push_front") == 0) {
			int num;
			scanf("%d", &num);
			dq.push_front(num);
		}
		else if (strcmp(str, "push_back") == 0) {
			int num;
			scanf("%d", &num);
			dq.push_back(num);
		}
		else if (strcmp(str, "pop_front") == 0) {
			printf("%d\n", dq.pop_front());
		}
		else if (strcmp(str, "pop_back") == 0) {
			printf("%d\n", dq.pop_back());
		}
		else if (strcmp(str, "size") == 0) {
			printf("%d\n", dq.size());
		}
		else if (strcmp(str, "empty") == 0) {
			printf("%d\n", dq.empty());
		}
		else if (strcmp(str, "front") == 0) {
			printf("%d\n", dq.front());
		}
		else if (strcmp(str, "back") == 0) {
			printf("%d\n", dq.back());
		}
	}
	*/

/*
	char str[100];
	cin.getline(str, 100);
	int len = strlen(str);
	while (len>0) {
		int arr[4] = { 0, };
		for (int i = 0; i < len; i++) {
			if ('a' <= str[i] && str[i] <= 'z') {
				arr[0]++;
			}
			else if ('A' <= str[i] && str[i] <= 'Z') {
				arr[1]++;
			}
			else if ('0' <= str[i] && str[i] <= '9') {
				arr[2]++;
			}
			else if (str[i] == ' ') {
				arr[3]++;
			}
		}

		for (int i = 0; i < 4; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");

		cin.getline(str, 100);
		len = strlen(str);
	}
	*/


	/*
	int arr[26];
	for (int i = 0; i < 26; i++) {
		arr[i] = -1;
	}

	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < 26; j++) {
			if (str[i] == (j + 97) && arr[j]== -1)
				arr[j] = i;
		}
	}

	for (int i = 0; i < 26; i++) {
		printf("%d ", arr[i]);
	}*/

/*
	char str[105];
	cin.getline(str, 105);
	int len = strlen(str);

	for (int i = 0; i < len; i++) {
		if ('A' <= str[i] && str[i] <= 'Z') {
			char c = str[i];
			if (c > 'M') {
				c = c - 26;
			}
			c = c + 13;
			printf("%c", c);
		}
		else if ('a' <= str[i] && str[i] <= 'z') {
			char c = str[i];
			if (c > 'm') {
				c = c - 26;
			}
			c = c + 13;
			printf("%c", c);
		}
		else {
			printf("%c", str[i]);
		}
	}*/
  

/*
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
	long long int r1, r2;
	
	int n;
	if (b < 10)
		n = 1;
	else if (b < 100)
		n = 2;
	else if (b < 1000)
		n = 3;
	else if (b < 10000)
		n = 4;
	else if (b < 100000)
		n = 5;
	else if (b < 1000000)
		n = 6;
	else if (b == 1000000)
		n = 7;

	r1 = a;
	for (int i = 0; i < n; i++)
		r1 *= 10;
	r1 += b;

	if (d < 10)
		n = 1;
	else if (d < 100)
		n = 2;
	else if (d < 1000)
		n = 3;
	else if (d < 10000)
		n = 4;
	else if (d < 100000)
		n = 5;
	else if (d < 1000000)
		n = 6;
	else if (d == 1000000)
		n = 7;

	r2 = c;
	for (int i = 0; i < n; i++)
		r2 *= 10;
	r2 += d;

	printf("%lld", r1+r2);
	*/

/*
    string a, b, c, d;
    cin>>a>>b>>c>>d;
    
    a+=b;
    c+=d;
    
    long long result = stoll(a) + stoll(c);
    
    cout<<result;
  */

/*
	string s;
	cin >> s;
	int len = s.length();
	
	char** c = new char* [len];
	for (int i = 0; i < len; i++)
		c[i] = new char[len];

	for (int i = 0; i < len; i++) {
		for (int j = i; j <= len; j++) {
			c[i][j-i] = s[j];
		}
	}

	
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len-1 -i; j++) {
			if (strcmp(c[j], c[j+1]) > 0) {
				char* tmp = c[j];
				c[j] = c[j + 1];
				c[j+1] = tmp;
			}
		}
	}
	
	for (int i = 0; i < len; i++)
		printf("%s\n", c[i]);
		*/

/*
	stack<char> left, right;
	char s[600000];
	scanf("%s", s);
	for (int i = 0; i < strlen(s); i++) {
		left.push(s[i]);
	}
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		char cmd;
		scanf(" %c", &cmd);
		switch (cmd) {
		case 'L':
			if (!left.empty()) {
				char c = left.top();
				left.pop();
				right.push(c);
			}
			break;
		case 'D':
			if (!right.empty()) {
				char c = right.top();
				right.pop();
				left.push(c);
			}
			break;
		case 'B':
			if(!left.empty())
				left.pop();
			break;
		case 'P':
			char in;
			scanf(" %c", &in);
			left.push(in);
			break;
		}
	}

	while (!left.empty()) {
		char c = left.top();
		left.pop();
		right.push(c);
	}

	while (!right.empty()) {
		char c = right.top();
		right.pop();
		printf("%c", c);
	}
	*/

	/*
	int n, k;
	cin >> n >> k;
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	cout<<"<";
	while (q.size()!=1) {
		for (int i = 1; i < k; i++) {
			q.push(q.front());
			q.pop();
		}
		cout<<q.front()<<", ";
		q.pop();	
	}
	cout<<q.front()<<">";
	*/

/*
	int arr[25];
	for (int i = 1; i <= 24; i++) {
		int num;
		cin >> num;
		arr[i] = num;
	}

	
	if ((arr[13] == arr[14] && arr[14] == arr[15] && arr[15] == arr[16]) && (arr[17] == arr[18] && arr[18] == arr[19] && arr[19]==arr[20])) {
		if ((arr[1] == arr[3] && arr[6] == arr[8] && arr[3] == arr[8])
			&&(arr[5]==arr[7]&&arr[10]==arr[12]&&arr[7]==arr[10])
			&&(arr[9]==arr[11]&&arr[21]==arr[23]&&arr[11]==arr[21])
			&&(arr[22]==arr[24]&&arr[2] == arr[4] &&arr[4]==arr[22])) {
			cout << 1;
		}
		else if ((arr[1] == arr[3] && arr[21] == arr[23] && arr[3] == arr[21])
			&& (arr[5] == arr[7] && arr[2] == arr[4] && arr[7] == arr[2])
			&& (arr[9] == arr[11] && arr[6] == arr[8] && arr[11] == arr[6])
			&& (arr[22] == arr[24] && arr[10] == arr[12] && arr[24] == arr[10])) {
			cout << 1;
		}
		else {
			cout << 0;
		}
	}
	else if ((arr[5] == arr[6] && arr[6] == arr[7] && arr[7] == arr[8]) && (arr[21] == arr[22] && arr[22] == arr[23] && arr[23]==arr[24])) {
		if ((arr[1] == arr[2] && arr[14] == arr[16] && arr[2] == arr[14])
			&& (arr[13] == arr[15] && arr[9] == arr[10] && arr[15] == arr[9])
			&& (arr[11] == arr[12] && arr[17] == arr[19] && arr[12] == arr[17])
			&& (arr[18] == arr[20] && arr[3] == arr[4] && arr[20] == arr[3])) {
			cout << 1;
		}
		else if ((arr[1] == arr[2] && arr[17] == arr[19] && arr[2] == arr[17])
			&& (arr[13] == arr[15] && arr[3] == arr[4] && arr[15] == arr[3])
			&& (arr[11] == arr[12] && arr[14] == arr[16] && arr[12] == arr[14])
			&& (arr[18] == arr[20] && arr[9] == arr[10] && arr[20] == arr[9])) {
			cout << 1;
		}
		else {
			cout << 0;
		}
	}
	else if ((arr[1] == arr[2] && arr[2] == arr[3] && arr[3] == arr[4]) && (arr[9] == arr[10] && arr[10] == arr[11] && arr[11]==arr[12])) {
		if ((arr[13] == arr[14] && arr[7] == arr[8] && arr[14] == arr[7])
			&& (arr[5] == arr[6] && arr[19] == arr[20] && arr[6] == arr[19])
			&& (arr[17] == arr[18] && arr[23] == arr[24] && arr[18] == arr[23])
			&& (arr[21] == arr[22] && arr[15] == arr[16] && arr[22] == arr[15])) {
			cout << 1;
		}
		else if ((arr[13] == arr[14] && arr[23] == arr[24] && arr[14] == arr[23])
			&& (arr[5] == arr[6] && arr[15] == arr[16] && arr[6] == arr[15])
			&& (arr[17] == arr[18] && arr[7] == arr[8] && arr[18] == arr[7])
			&& (arr[21] == arr[22] && arr[19] == arr[20] && arr[22] == arr[19])) {
			cout << 1;
		}
		else {
			cout << 0;
		}
	}
	else {
		cout << 0;
	}
	*/


	/*
	int a, b;
	cin >> a >> b;
	
	int min;
	if (a > b)
		min = b;
	else
		min = a;
	
	int m1, m2;
	for (int i = min; i >=1; i--) {
		if (a % i == 0 && b % i == 0) {
			m1 = i;
			break;
		}
	}

	
	int max;
	if (a > b)
		max = a;
	else
		max = b;

	for (int i = max; i <= a * b; i++) {
		if (i % a == 0 && i % b == 0) {
			m2 = i;
			break;
		}
	}

	cout << m1 << "\n";
	cout << m2 << "\n";
	*/

/*
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int a, b;
		cin >> a >> b;

		int max;
		if (a > b)
			max = a;
		else
			max = b;

		int result;
		for (int j = max; j <= a * b; j++) {
			if (j % a == 0 && j % b == 0) {
				result = j;
				break;
			}
		}

		cout << result << "\n";
	}
	*/

	long long int a, b;
	cin >> a >> b;

	return 0;


}



unsigned long long int pow(int n, int k) {
	if (k == 1) {
		return n;
	}
	else if (k % 2 == 0) {
		return (pow(n, k / 2)*pow(n,k/2))%1000000007;
	}
	else {
		return ((pow(n, k/2)*pow(n, k/2))%1000000007 * n)%1000000007;
	}
}