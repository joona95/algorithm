#include <string>
#include <vector>
#include <set>
#include <cstdio>

using namespace std;


string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    multiset<string> s;
    s.insert(completion.begin(), completion.end());
    
    for(int i=0;i<participant.size();i++){
        if(s.end()!=s.find(participant[i])){
            s.erase(s.find(participant[i]));
        }
        else{
            answer = participant[i];
            break;
        }
    }
    
    
    
    return answer;
}

/*
다른사람의 코드

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    for(int i=0;i<completion.size();i++)
    {
        if(participant[i] != completion[i])
            return participant[i];
    }
    return participant[participant.size() - 1];
    //return answer;
}

*/