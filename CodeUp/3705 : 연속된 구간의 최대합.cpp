#include <iostream>
using namespace std;


int dp[100001];
int arr[100001];
int main(){
    
    int N; cin>>N;
    
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    
    int ans=arr[0];
    dp[0]=arr[0];
    for(int i=1;i<N; i++){
        dp[i]=max(arr[i],dp[i-1]+arr[i]);
        ans=max(ans,dp[i]);
    }
    cout<<ans;
}
