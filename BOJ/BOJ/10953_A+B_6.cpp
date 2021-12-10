#include <cstdio>

using namespace std;

int main()
{
    int a, b;
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int a, b;
        scanf("%d,%d", &a, &b); //입력값 사이에 ','가 있을 때 어떻게 받을 것인가가 중요
        printf("%d\n", a + b);
    }
    return 0;
}