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
    scanf("%d%d", &a, &b);
    printf("%d", a + b);
    return 0;
}

/*
메모리 1112KB
scanf() 사용 시 %d %d 사이를 굳이 '\n'으로 정확하게 표시 안해줘도 됨.
붙여도 같은 결과. 띄워도 같은 결과. '\n' 사용해도 같은 결과. 심지어 '\n\n'해도 상관없었음
*/