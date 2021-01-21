#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    map<string, int> m;
    
    for(int i=0;i<clothes.size();i++){
        m[clothes[i][1]]+=1;
    }
    
    for(map<string, int>::iterator iter=m.begin();iter!=m.end();iter++){
        answer*=(iter->second + 1);
    }
    answer--;
    
    return answer;
}

/*
부분 집합의 개수 구하기
처음엔 multimap<string, string> 에서 set<string>으로 multimap.count(key)를 구하려고 했는데 생각해보니 이럴 필요가 없음.
map<string, int>로 가능.

총 개수 구하기 = (한 종류에 있는 옷 개수 + 1 (아무것도 선택하지 않은 경우))에 대해서 모든 종류의 값을 곱해줌
여기서 모든 종류를 아무것도 선택하지 않은 경우 하나를 빼줌.
*/