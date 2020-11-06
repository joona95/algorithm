#include <string>
#include <vector>
#include <set>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    set<string> s;
    s.insert(phone_book.begin(), phone_book.end());
    
    for(set<string>::iterator i=s.begin();i!=s.end();){
        string tmp = *i;
        i++;
        for(set<string>::iterator j=i;j!=s.end();j++){
            if((*j).substr(0, tmp.length())==tmp){
                answer=false;
                return answer;
            }
        }
    }
    
    return answer;
}


/*
정렬활용한 다른 코드
이게 더 효율적인듯


#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool solution(vector<string> phoneBook) {
    bool answer = true;

    sort(phoneBook.begin(), phoneBook.end());

    for ( int i = 0 ; i < phoneBook.size() - 1 ; i++ )
    {
        if ( phoneBook[i] == phoneBook[i+1].substr(0, phoneBook[i].size()) )
        {
            answer = false;
            break;
        }
    }

    return answer;
}
*/