#include <cstdio>

using namespace std;

int main()
{
    int a, b;
    /*
    scanf("%d %d", &a, &b);
    while (!(a == 0 && b == 0))
    {
        printf("%d\n", a + b);
        scanf("%d %d", &a, &b);
    }
    */
    while (1)
    {
        scanf("%d %d", &a, &b);
        if (a == 0 && b == 0)
            break;
        printf("%d\n", a + b);
    }
    //이렇게 푼 사람이 많음.
    return 0;
}