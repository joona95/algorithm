#include <string>
#include <vector>
#include <queue>
#include <cstdio>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int w = 0;
    int idx = 0;
    queue<int> q;
    
    while(1){
        
        if(idx==truck_weights.size()){
            answer += bridge_length;
            break;
        }
        
        answer ++;
        
        if(q.size()==bridge_length){
            w-=q.front();
            q.pop();
        }
        
        if(w+truck_weights[idx]<=weight){
            q.push(truck_weights[idx]);
            w+=truck_weights[idx];
            idx++;
        }
        else{
            q.push(0);
        }
        
    }
    
    
    return answer;
}

//다리에 올라갈 수 없는 트럭 나오면 0을 삽입
//큐 맨앞을 빼는 순간 새로운 트럭 삽입
//마지막 트럭 삽입되는 순간에는 bridge_length만큼 추가해주면서 break