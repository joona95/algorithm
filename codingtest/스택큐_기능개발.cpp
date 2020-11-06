#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int front = 0;
    int end = progresses.size()-1;
    
    while(front<=end){
        for(int i=0;i<speeds.size();i++){
            if(progresses[i]+speeds[i]<=100){
                progresses[i]+=speeds[i];
            }
            else{
                progresses[i]=100;
            }
        }
        
        int cnt=0;
        while(progresses[front]==100){
            cnt++;
            front++;
        }
        
        if(cnt!=0)
            answer.push_back(cnt);
    }
    
    return answer;
}

/*
좀 더 효율적인 코드 (반복문 하나)

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    int day;
    int max_day = 0;
    for (int i = 0; i < progresses.size(); ++i)
    {
        day = (99 - progresses[i]) / speeds[i] + 1;

        if (answer.empty() || max_day < day)
            answer.push_back(1);
        else
            ++answer.back();

        if (max_day < day)
            max_day = day;
    }

    return answer;
}


*/
