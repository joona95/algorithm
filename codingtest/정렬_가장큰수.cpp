#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp (string s1, string s2){
    return stoi(s1+s2) > stoi(s2+s1);
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> str;
    for(int i=0;i<numbers.size();i++){
        str.push_back(to_string(numbers[i]));
    }
    
    sort(str.begin(), str.end(), cmp);
    
    if(str[0]=="0"){
        return "0";
    }
    
    for(int i=0;i<str.size();i++){
        answer += str[i];
    }
    
    return answer;
}


/*
반례 : [0,0,0,0,0]
결과 : "0"
고려못함.
*/