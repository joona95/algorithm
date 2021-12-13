#include <cstdio>

using namespace std;

int main()
{
    int n;
    scanf("%d\n", &n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        char c;
        scanf("%c", &c);
        sum += (c - 48); // 48=='0' 이므로 sum += c - '0' 해도 됨.
    }
    printf("%d", sum);
    return 0;
}

/*
처음에 cstdlib의 atoi를 생각했었는데,
그럴 필요가 없었음. 
*/