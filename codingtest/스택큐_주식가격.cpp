#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    int n=prices.size();
    vector<int> answer(n);
    
    stack<int> s;
    s.push(0);
    for(int i=1;i<n;i++){
        while(!s.empty() && prices[s.top()]>prices[i]){
            answer[s.top()]=i-s.top();
            s.pop();
        }
        s.push(i);
    }
    
    while(!s.empty()){
        int top = s.top();
        answer[top]=n-1-top;
        s.pop();
    }    

    return answer;
}

/*
1.아무래도 이중포문은 제일 간단하지만 효율성떨어짐
2. stack에 쌓인거랑 현재랑 다 비교해줘야함******
3.공간복잡도 문제는 아니었음. pair<int, int> 스택
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    int n=prices.size();
    vector<int> answer(n);
    
    stack<pair<int,int>> s;
    s.push(make_pair(prices[0],0));
    for(int i=1;i<n;i++){
        while(!s.empty() && prices[s.top().second]>prices[i]){
            answer[s.top().second]=i-s.top().second;
            s.pop();
        }
        s.push(make_pair(prices[i],i));
    }
    
    while(!s.empty()){
        int top = s.top().second;
        answer[top]=n-1-top;
        s.pop();
    }    

    return answer;
}
    

*/