#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool mvCmp(const pair<string,int>& a, const pair<string,int>& b) {
	return a.second > b.second;
}

bool mmvCmp(const pair<string,pair<int,int>>& a, const pair<string,pair<int,int>>& b) {
	if(a.second.first==b.second.first){
        return a.second.second < b.second.second;
    }
    else{
        return a.second.first > b.second.first;
    }
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    map<string, int> m;
    multimap<string, pair<int,int>> mm;
    for(int i=0;i<genres.size();i++){
        mm.insert(make_pair(genres[i],make_pair(plays[i], i)));
        int cnt = m[genres[i]];
        m[genres[i]]+=plays[i];
    }
    
    vector<pair<string,int>> mv(m.begin(), m.end());
    
    sort(mv.begin(), mv.end(), mvCmp);
    
    for(int i=0;i<mv.size();i++){
        //printf("%s %d\n",(mv[i].first).c_str(), mv[i].second);
        
        vector<pair<string,pair<int,int>>> mmv(mm.lower_bound(mv[i].first),mm.upper_bound(mv[i].first));
        
        sort(mmv.begin(),mmv.end(),mmvCmp);
        
        /*
        for(int j=0;j<mmv.size();j++){
            printf("%s %d %d\n",(mmv[j].first).c_str(), mmv[j].second.first, mmv[j].second.second);
        }*/
        
        answer.push_back(mmv[0].second.second);
        
        if(mmv.size()>1){
            answer.push_back(mmv[1].second.second);
        }
    }

    return answer;
}
/*
map, multimap을 vector로 바꾼 다음 sort 하기
*/