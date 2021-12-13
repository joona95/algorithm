/*
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int length = s.length();
    for (int i = 0; i < length; i += 10)
    {
        cout << s.substr(i, 10) << "\n"; //string substr (size_t pos = 0, size_t len = npos) const;

    }
    return 0;
}
*/

#include <cstdio>

int main()
{
    char str[105];
    scanf("%s", str);
    int i = 0;
    while (str[i] != '\0') //문자열의 마지막을 나타내는 null 문자
    {
        printf("%c", str[i]);
        i++;
        if (i % 10 == 0)
        {
            printf("\n");
        }
    }
    return 0;
}