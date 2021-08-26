#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

class Color {
public:
	Color(int x, int y) {
		a = x;
		b = y;
	}

	 void ColorPrint(Color A, Color B) {
		cout << A.a << A.b << endl;
		cout << B.a << B.b << endl;
	}

private:
	int a;
	int b;
};

class GameWindow {
public:
	GameWindow();
	GameWindow(const int, const int);

	int GetWidth() const;
	int GetHeight() const;
	void ResizeWindow(const int, const int);

private:
	int width;
	int height;
};

GameWindow::GameWindow() : width(800), height(600) { }
GameWindow::GameWindow(const int w, const int h) {
	ResizeWindow(w, h);
	/*
	if (w < 800)
		width = 800;
	else
		width = w;
	if (h < 600)
		width = 600;
	else
		height = h;
	*/
}

int GameWindow::GetWidth() const { return width; }
int GameWindow::GetHeight() const { return height; }
void GameWindow::ResizeWindow(const int w, const int h) {
	if (w < 800)
		width = 800;
	else
		width = w;
	if (h < 600)
		width = 600;
	else
		height = h;
}

int parity(int n) {
	if (n % 2 == 0)
		return 0;
	else
		return 1;
}

void print_noSpace(const char *str) {
	int i = 0;
	while (str[i] != '\0') {
		if(str[i]!=' ')
			printf("%c", str[i]);
		i++;
	}
}

int main() {
	//Color x(0, 0);
	//Color y(1, 1);

	//Color::ColorPrint(x, y);

	/*
	int num;
	int arr[105];

	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 1; i < num; i = i + 2) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	for (int i = 0; i < num; i = i + 2) {
		printf("%d ", arr[i]);
	}
	

	int r, c;
	int arr[12][12];

	scanf("%d%d", &r, &c);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < r; i++) {
		int sum = 0;
		for (int j = 0; j < c; j++) {
			sum += arr[i][j];
		}
		printf("%d\n", sum);
	}
	*/

	/*
	string s;
	getline(cin, s);
	cout << s << endl;
	


	int t;
	cin >> t;

	int* a = new int[t];
	int* b = new int[t];

	for (int i = 0; i < t; i++) {
		cin >> a[i] >> b[i];
	}

	for (int i = 0; i < t; i++) {
		cout << "Case #" << i + 1 << ": " << a[i] << " + " << b[i] << " = " << a[i] + b[i] << endl;
	}
	*/
	/*
	int n;
	char num[105];

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	int sum = 0;
	for (int i = 0; i < n; i++) {
		char c[2];
		c[0] = num[i];
		c[1] = '\0';
		sum += atoi(c);
	}

	cout << sum << endl;
	*/

	/*
	string str;
	cin >> str;
	int l = str.length();

	int i;	
	for (i = 0; i < (l / 10); i++) {
		for (int j = i * 10; j < i*10 + 10; j++) {
			cout << str[j];
		}
		cout << endl;
	}
	
	for (int j = i * 10; j < l; j++) {
		cout << str[j];
	}
	*/

	/*
	for (int i = 1; i < 10000; i++) {
		bool check = false;

		for (int x = 0; x < 10; x++) {
			for (int y = 0; y < 10; y++) {
				for (int z = 0; z < 10; z++) {
					for (int w = 0; w < 10; w++) {
						if (i == (1001 * x + 101 * y + 11 * z + 2 * w)) {
							check = true;
						}
					}
				}
			}
		}

		
		if (check == false) {
			cout << i << endl;
		}
	}
	*/

/*
	int arr[3][4] = { {1, 2, 3, 4},{5, 6, 7, 8},{9, 10, 11, 12} };

	int(*ptr)[3][4] = &arr;

	int a[10][2] = { 0 };

	for (int i = 0; i < 10; i++) {
		cout << a[i][0]<<"," << a[i][1]<<endl;
	}
	*/


/*
	int n, m;
    char arr[50][50];
    
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
			cin >> arr[i][j];
        }
    }
    
	int s[10] = { 0 };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = j; k < m; k++) {
				if (arr[i][j] == arr[i][k]&&(k-j)<(n-i))
					if(arr[i][j] == arr[i + (k - j)][j] && arr[i][j] == arr[i + (k - j)][k]) {
						int size = k - j + 1;
						if (s[(int)(arr[i][j]-'0')] < size) {
							s[(int)(arr[i][j]-'0')] = size;
						}
				}
			}
		}
	}

	int max = 0;
	for (int i = 0; i < 10; i++) {
		if (s[i] > max)
			max = s[i];
	}

	cout << max * max;
	*/


/*
	int m, d;
    cin >>m>>d;
    
    int date[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    int sum = 0;
    for(int i=0;i<m-1;i++){
        sum += date[i];
    }
    
    sum += d;
    
    int day = sum%7;
    switch(day){
        case 0:
            cout<<"SUN"<<endl;
            break;
        case 1:
            cout<<"MON"<<endl;
            break;
        case 2:
            cout<<"TUE"<<endl;            
            break;
        case 3:
            cout<<"WED"<<endl;
            break;
        case 4:
            cout<<"THU"<<endl;
            break;
        case 5:
            cout<<"FRI"<<endl;
            break;
        case 6:
            cout<<"SAT"<<endl;
            break;
    }
	*/

	/*
	int m, d;
	cin >> m >> d;

	for (int i = 1; i < m; i++) {
		if (i == 2) { d += 28; }
		else if(i == 1 | i == 3 | i == 5 | i == 7 | i == 8 | i == 10 | i == 12) { d += 31; }
		else { d += 30; }
	}
	d %= 7;
	switch (d-1) {
	case 0:
		cout << "MON";
		break;
	case 1:
		cout << "TUE";
		break;
	case 2:
		cout << "WED";
		break;
	case 3:
		cout << "THU";
		break;
	case 4:
		cout << "FRI";
		break;
	case 5:
		cout << "SAT";
		break;
	case 6:
		cout << "SUN";
		break;
    default:
        break;
	}*/
	//int n = 5;
	//int* arr = new int[n];

/*
    int n;
    cin >>n;

    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    int min=1000000, max=-1000000;    
    for(int i=0;i<n;i++){
        if(min>arr[i]){
            min = arr[i];
        }
        
        if(max<arr[i]){
            max = arr[i];
        }
    }
    
    cout<<min<<" "<<max<<endl;
  */

/*
	int n;
    cin>>n;
    
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
	*/

	/*
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n - i; j++) {
			cout << " ";
		}
		for (int j = 1; j <= i; j++) {
			cout << "*";
		}
		cout << endl;
	}
	*/

	/*
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= n - i; j++) {
			cout << "*";
		}
		cout << endl;
	}
	*/

	/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			cout << " ";
		}
		for (int j = 0; j < n - i; j++) {
			cout << "*";
		}
		cout << endl;
	}
	*/

	/*
	int n;
	cin >> n;

	queue<pair<int,int>> q;
	int cnt = 0;
	q.push(make_pair(n,cnt));
	while (q.front().first != 1) {
		n = q.front().first;
		cnt = q.front().second + 1;

		q.pop();
		if ((n % 3) == 0) {
			q.push(make_pair((n / 3), cnt));
		}
		if ((n % 2) == 0) {
			q.push(make_pair((n / 2),cnt));
		}
		q.push(make_pair(n - 1,cnt));
	}

	cout << q.front().second << endl;
	*/

   //int n;
    //cin >>n;
    
	/*
    int k=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++){
            cout<<" ";
        }
        for(int j=1;j<=k;j++){
			cout << "*";
        }
		k += 2;

        cout<<endl;
    }*/

	/*
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= i; j++) {
			cout << "*";
		}
		for (int j = 1; j <= 2*(n - i); j++) {
			cout << " ";
		}
		for (int j = 1; j <= i; j++) {
			cout << "*";
		}
		cout << endl;
	}
	for (int i = n; i > 0; i--) {
		for (int j = 1; j <= i; j++) {
			cout << "*";
		}
		for (int j = 1; j <= 2*(n - i); j++) {
			cout << " ";
		}
		for (int j = 1; j <= i; j++) {
			cout << "*";
		}
		cout << endl;
	}*/

	/*
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= n - i; j++) {
			cout << " ";
		}
		for (int j = 1; j <= i; j++) {
			cout << "*";
		}
		cout << endl;
	}
	for (int i = n; i > 0; i--) {
		for (int j = 1; j <= n - i; j++) {
			cout << " ";
		}
		for (int j = 1; j <= i; j++) {
			cout << "*";
		}
		cout << endl;
	}
	*/

	/*
	for (int i = n; i > 0; i--) {
		for (int j = 1; j <= n - i; j++) {
			cout << " ";
		}
		for (int j = 1; j <= (2 * i - 1); j++) {
			cout << "*";
		}
		cout << endl;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= n - i; j++) {
			cout << " ";
		}
		for (int j = 1; j <= (2 * i - 1); j++) {
			cout << "*";
		}
		cout << endl;
	}*/

	/*
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n - i; j++) {
			cout << " ";
		}
		for (int j = 1; j <= i; j++) {
			cout << "* ";
		}
		cout << endl;
	}*/

/*
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= n - i; j++) {
			cout << " ";
		}
		cout << "*";
	
		if (i > 1) {
			for (int j = 1; j < 2 * (i - 1); j++) {
				cout << " ";
			}
			cout << "*";
		}
		cout << endl;
	}
	for (int i = 1; i <= 2 * n - 1; i++) {
		cout << "*";
	}
*/

/*
	int a,b;
    cin >> a >> b;
    
    int arr[1001];
    int k=1;
    for(int i=1;i<=45;i++){
        for(int j=1;j<=i;j++){
			if (k == 1001)
				break;
			arr[k]=i;
            k++;
        }
    }
    
	int sum = 0;
	for (int i = a; i <= b; i++) {
		sum += arr[i];
	}

	cout << sum << endl;
	*/

/*
	int n, a, b;
    cin >> n>>a>>b;
    
    int level=1;
    for(int i=n;i!=1;i/=2){
        if((a-1)/2 == (b-1)/2)
            break;
        if(a%2==0)
            a/=2;
        else
            a = a/2 +1;
        if(b%2==0)
            b/=2;
        else
            b= b/2 +1;
        level++;
    }
    
    cout<<level<<endl;
	*/

	//0 10 0 20
	
/*
    int n, s;
    cin >>n>>s;
    
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
  */  
	/*
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<n-i;j++){
            int sum=0;
            for(int k=j;k<j+i;k++){
                sum+=arr[k];
            }
            if(sum>=s){
				cnt = i;
                break;
            }
        }
		if (cnt != 0) {
			break;
		}
    }*/
	/*
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = i; j < n; j++) {
			sum += arr[j];
			if (sum >= s && (cnt==0 || cnt > j - i)) {
				cnt = j - i+1;
				break;
			}
		}
	}*/
/*
	int cnt = 0, sum = 0, l = 0, h = 0;
	while (l<=h && h<=n) {
		if (sum < s)
			sum += arr[h++];
		else {
			sum -= arr[l++];
			if (cnt == 0 || cnt > h - l+1) {
				cnt = h - l + 1;
				cout << cnt << ", " << l << "," << h << endl;
			}
		}
	}
  */  
	//cout << cnt << endl;
   
    //delete[] arr;

/*
	int n;
	cin >> n;

	
	int sum = 1;
	for (int i = 1; i <= n/2; i++) {
		unsigned long s = 1;
		int j, k;
		if (n - 2 * i > i) {
			j = n - 2 * i + 1;
			k = i;
		}
		else { 
			j = i+1;
			k = n - 2 * i;
		}
		for (;j <= n - i; j++)
			s *= j;
		cout << s << endl;
		for (; k > 0; k--)
			s /= k;
		cout << s << endl;
		sum += s;
	}
	//sum = sum % 10007;

	cout << sum << endl;
	*/

/*
    int n;
    cin>>n;
    int arr[1001];
    arr[1] = 1;
    arr[2] = 2;
    
    for(int i=3;i<=1000;i++){
        arr[i]=(arr[i-1]+arr[i-2])%10007;
    }
    
    cout<<arr[n]<<endl;
	*/

/*
    int n, m, x=0;
    cin>>n>>m;
    int *arr = new int[n];
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int sum=0;
    for(int i=0;i<n;i++){
        sum += arr[i];
        for(int j=0;j<i;j++){
            if(arr[j]>arr[i]){
                int tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
            }
        }        
    }
    
	sum -= m;
    for(int i=n;i>0;i--){
        if(sum%i ==0 && (arr[n-i]>sum/i))
            x = sum/i;
        else
            sum -= arr[n-i];
    }
    
    cout<<x<<endl;
	*/

	//printf("%d\n", parity(5));
	//printf("%d\n", parity(-3));
	//printf("%d\n", parity(6));

	//print_noSpace("Hello, World!\n");
	//print_noSpace("My name is Doodle\n");

	/*2805¹ø¹®Á¦
    int n, m, x=0;
    cin>>n>>m;
    int *arr = new int[n];
    int min=0, max=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(max < arr[i])
            max = arr[i];
    }
	//cout << max << endl;
	
    while(min<=max){
		int sum = 0;
        int mid = (min+max)/2;
        for(int i=0;i<n;i++){
            if(mid < arr[i]){
                sum += arr[i]- mid;
            }
        }
		//cout << sum << " " << cnt << " " << mid<<endl;
        
		if (sum >= m) {
			if (x < mid)
				x = mid;
			min = mid + 1;
		}
		else
			max = mid - 1;
    }
    
    cout<<x<<endl;
    */

/*
    int a, b, n;
    cin >> a>>b>>n;
    int *x = new int[n];
    int *y = new int[n];
    for(int i=0;i<n;i++)
        cin>>x[i]>>y[i];
    
    double min = 1000/(double)b*a;
    for(int i=0;i<n;i++){
        double m = 1000/(double)y[i]*x[i];
        if(m<min)
            min = m;
    }
	cout << fixed;
	cout.precision(2);
    cout<<min<<endl;
	*/

/*
	int t, test[4];
	cin >> t;
	int* n = new int[t];
	for (int i = 0; i < t; i++)
		cin >> n[i];


	for (int j = 0; j < t; j++) {
		int sum = 0;
		for (int i = n[j] / 3; i >= 0; i--) {
			test[3] = i;
			for (int k = (n[j] - 3 * test[3]) / 2; k >= 0; k--) {
				int cnt = 1;
				test[2] = k;
				test[1] = n[j] - 3 * test[3] - 2 * test[2];
				for (int a = test[3] + test[2] + test[1]; a > 0; a--)
					cnt *= a;
				for (int a = test[3]; a > 0; a--) {
					cnt /= a;
				}
				for (int a = test[2]; a > 0; a--) {
					cnt /= a;
				}
				for (int a = test[1]; a > 0; a--) {
					cnt /= a;
				}
				sum += cnt;
			}
		}
		cout << sum << endl;
	}
	*/

/*
    int n, test[10]={0,1,1,1,1,1,1,1,1,1};
    cin >>n;
    
    for(int i=1;i<n;i++){
		int test2[10] = { 0 };
		test2[0] = test[1];
        for(int j=1;j<9;j++){
			test2[j] = (test[j - 1] + test[j + 1]) % 1000000000;
        }
		test2[9] = test[8];

		for (int j = 0; j < 10; j++) {
			test[j] = test2[j];
			cout << test[j] << " ";
		}
		cout << endl;
    }
    
    int sum=0;
    for(int i=0;i<10;i++)
        sum = (sum + test[i]) % 1000000000;
    
    cout<<sum<<endl;
	*/
/*
	int n;
	cin >> n;

	int sum = 1;
	for (int i = 1; i <= n/2; i++) {
		unsigned long s = 1;
		int j, k;
		if (n - 2 * i > i) {
			j = n - 2 * i + 1;
			k = i;
		}
		else { 
			j = i+1;
			k = n - 2 * i;
		}
		for (;j <= n - i; j++)
			s *= j;
		//cout << s << endl;
		for (; k > 0; k--)
			s /= k;
		//cout << s << endl;
		sum += s;
	}
	//sum = sum % 10007;

	cout << sum << endl;
	*/
    int n;
    cin >>n;
    
    int *arr=new int[n+1];
    arr[1] = 1;
    arr[2] = 3;
    
    for(int i=3;i<=n;i++){
        arr[i]=2*arr[i-2]+arr[i-1];
    }
    
    cout<<arr[n]<<endl;

	return 0;
}