#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int n[3]={5,8,10};
    int stu1[5]={1,2,3,4,5};
    int stu2[8]={2,1,2,3,2,4,2,5};
    int stu3[10]={3,3,1,1,2,2,4,4,5,5};
    
    int num[3]={0,};
    for(int i=0;i<answers.size();i++){
        if(stu1[i%n[0]]==answers[i]){
            num[0]++;
        }
        if(stu2[i%n[1]]==answers[i]){
            num[1]++;
        }
        if(stu3[i%n[2]]==answers[i]){
            num[2]++;
        }
    }
    

    int max=-1;
    for(int i=0;i<3;i++){
        if(max<num[i]){
            max=num[i];
        }
    }
    
    for(int i=0;i<3;i++){
        if(max==num[i]){
            answer.push_back(i+1);
        }
    }
    
    return answer;
}