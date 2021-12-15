#include <cstdio>

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) // int i=n;i>0;i--
    {
        for (int j = 1; j <= n - i; j++) // int j=i;j>0;j--
        {
            printf("*");
        }
        printf("\n");
    }
}