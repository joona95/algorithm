//#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int a, b;
    /*
    cin >> a >> b;
    cout << a + b;
    */
    scanf("%d %d", &a, &b);
    printf("%d", a + b);
    return 0;
}

/*
iostream 은 2020KB 메모리
cstdio 는 1112KB 메모리
*/