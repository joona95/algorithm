#include <cstdio>

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            printf(" ");
        }
        printf("*");
        if (i > 1)
        {
            for (int j = 1; j <= 2 * (i - 1) - 1; j++)
            {
                printf(" ");
            }
            printf("*");
        }
        printf("\n");
    }
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        printf("*");
    }
    return 0;
}