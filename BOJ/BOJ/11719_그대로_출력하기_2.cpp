#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    while (getline(cin, s))
    {
        cout << s << "\n";
    }
    return 0;
}

/* 
'\n'만 있는 빈줄의 경우 's==""'이 된다. 그래서 이전처럼 'if(s=="") return 0' 사용하면 안됨.
eof에 도달하면 멈추므로 빈줄도 cout에서 "\n"하고 있으므로 반영 가능.
*/