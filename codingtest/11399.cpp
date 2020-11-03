#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    int *arr = new int[n];
    
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    
    sort(arr, arr+n);
    
    int sum=arr[0];
    for(int i=1;i<n;i++){
        arr[i]=arr[i]+arr[i-1];
        sum+=arr[i];
    }
    
    printf("%d\n", sum);
    
    return 0;
}

/*
3 1 4 3 2 
1 2 3 3 4 
1 3 6 9 13
*/
