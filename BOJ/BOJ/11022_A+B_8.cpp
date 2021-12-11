#include <cstdio>

using namespace std;

int main()
{
    int t;
    scanf("%d\n", &t);
    for (int i = 1; i <= t; i++)
    {
        int a, b;
        scanf("%d %d\n", &a, &b);
        printf("Case #%d: %d + %d = %d\n", i, a, b, a + b);
    }
    return 0;
}