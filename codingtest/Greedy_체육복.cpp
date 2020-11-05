#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    answer = n - lost.size();
    
    int stu[32]={0,};
    for(int i=1;i<=n;i++){
        stu[i]=1;
    }
    
    for(int i=0;i<reserve.size();i++){
        stu[reserve[i]]++;
    }
    
    for(int i=0;i<lost.size();i++){
        stu[lost[i]]--;
    }
    
    for(int i=0;i<reserve.size();i++){
        if(stu[reserve[i]]==2){
            if(reserve[i]-1>0 && stu[reserve[i]-1]==0){
                stu[reserve[i]-1]=1;
                answer++;
            }
            else if(reserve[i]+1<=n&& stu[reserve[i]+1]==0){
                stu[reserve[i]+1]=1;
                answer++;
            }
        }
        else if(stu[reserve[i]]==1){
            answer++;
        }
    }
    
    return answer;
}