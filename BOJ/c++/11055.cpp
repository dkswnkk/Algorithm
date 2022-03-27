#include <iostream>
using namespace std;


int arr[1001];
int dp[1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N; cin>>N;
    for(int i=0; i<N; i++){
        cin>>arr[i];
        dp[i]=arr[i];
    }
    
    int ans = arr[0];
    
    for(int i=0; i<=N; i++){
        for(int k=0; k<=i; k++){
            if(arr[i]>arr[k]) dp[i] = max(dp[i], arr[i] + dp[k]);
            ans = max(ans, dp[i]);
        }
    }
    cout<<ans;
}
