#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    int l = location;
    while(!priorities.empty()){
        int j = priorities[0];
        int idx=1;
        for(;idx<priorities.size();idx++){
            if(j<priorities[idx]){
                priorities.erase(priorities.begin());
                priorities.push_back(j);
                if(l==0){
                    l = priorities.size()-1;
                }
                else{
                    l--;
                }
                break;
            }
        }
        
        if(idx==priorities.size()){
            priorities.erase(priorities.begin());
            answer++;
            if(l==0){
                break;
            }
            else{
                l--;
            }
        }
    }
    
    
    return answer;
}