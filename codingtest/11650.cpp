#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> v;
    for(int i=0;i<n;i++){
        int a,b;
        scanf("%d %d", &a, &b);
        v.push_back(make_pair(a, b));
    }
    
    sort(v.begin(), v.end());
    
    for(int i=0;i<n;i++){
        printf("%d %d\n", v[i].first, v[i].second);
    }
}