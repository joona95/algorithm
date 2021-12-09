//#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int a, b;
    /*
    while (cin >> a >> b)
    {
        cout << a + b << "\n";
    }*/
    while (scanf("%d %d", &a, &b) != EOF)
    {
        printf("%d\n", a + b);
    }

    return 0;
}

/*
테스트 케이스가 주어지지 않는 경우
while(cin>>a>>b){}
while(scanf("%d %d", &a, &b)!=EOF){}
*/