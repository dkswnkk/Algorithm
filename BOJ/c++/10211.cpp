//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/10211
//  BOJ10211 Maximum Subarray


#include <iostream>
#include <algorithm>

int dp[1001],arr[1001];
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        int ans = arr[0];
        dp[0]= arr[0];
        
        for(int i=1; i<n; i++){
            dp[i] = max(dp[i-1]+arr[i],arr[i]);
            ans = max(dp[i],ans);
        }
        cout<<ans<<'\n';
    }
}
