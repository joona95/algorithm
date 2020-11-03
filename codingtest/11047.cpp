#include <cstdio>
using namespace std;

int main(){
    int n,k;
    scanf("%d %d", &n, &k);
    int arr[11];
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    
    int cnt=0;
    for(int i=n-1;i>=0;i--){
        int c=k/arr[i];
        cnt+=c;
        k-=c*arr[i];
    }
    
    printf("%d", cnt);
    
    return 0;
}