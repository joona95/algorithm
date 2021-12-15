#include <cstdio>

int main()
{
    int n;
    scanf("%d", &n);
    int max = -1000001;
    int min = 1000001;
    for (int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        if (max < num)
        {
            max = num;
        }
        if (min > num)
        {
            min = num;
        }
    }
    printf("%d %d", min, max);
    return 0;
}