#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end());
    
    for(int i=0;i<citations.size();i++){
        if(citations[i]<=(citations.size()-i)){
            answer = citations[i];
        }
        else{
            if(answer<(citations.size()-i)){
                answer = citations.size()-i;
            }
        }
    }
    
    return answer;
}

/*
[3, 0, 6, 1, 5] 3
[12, 11, 10, 9, 8, 1] 5
[6, 6, 6, 6, 6, 1] 5
[4, 4, 4] 3
[4, 4, 4, 5, 0, 1, 2, 3] 4
[10, 11, 12, 13] 4
[3, 0, 6, 1, 5] 3
[0, 0, 1, 1] 1
[0, 1] 1
[10, 9, 4, 1, 1] 3

citations에 직접적으로 주어진 숫자가 아닌 경우도 생각해줬어야 함.
*/