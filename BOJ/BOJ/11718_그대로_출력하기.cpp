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
    /*
    while (1)
    {
        getline(cin, s);
        if (s == "")
            return 0;
        cout << s << "\n";
    }
    //이것도 가능함.
    */
    return 0;
}

/*
cin 사용하면 출력 초과
getline 사용해야 공백까지 저장 가능
getline 함수는 입력받은 문자열을 그대로 리턴하여 정상적인 입력일 경우 0 이 아닌 값을 반환하여 while 루프의 조건으로 지정 가능

1) cin.getline(변수 주소, 최대 입력 가능 문자수, 종결 문자);
2) getline(입력스트림 오브젝트, 문자열을 저장할 string객체, 종결 문자);

```
int n;
string str;
cin >> n;
getline(cin, str);
```
이 경우 정수 값 입력후 '\n'가 남아있어서 geline 사용 시 '\n'이 포함됨
이를 해결하기 위해 cin 이후 getline 사용 전에 'cin.ignore();' 추가해주면됨
*/