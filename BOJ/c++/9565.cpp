//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/9465
//  BOJ9465 스티커

#include <iostream>
#include <algorithm>

using namespace std;

int dp[2][100001];
int arr[2][100001];

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T; cin>>T;
    
    while(T--){
        
        int n; cin>>n;
        for(int i=0; i<2; i++){
            for(int k=0; k<n; k++){
                cin>>arr[i][k];
            }
        }
        
        dp[0][0] = arr[0][0];
        dp[1][0] = arr[1][0];
        dp[0][1] = arr[0][1]+dp[1][0];
        dp[1][1] = arr[1][1]+dp[0][0];
        
        for(int k=1; k<n; k++){
            dp[0][k] = max(dp[0][k-1],dp[1][k-1]+arr[0][k]);
            dp[1][k] = max(dp[1][k-1],dp[0][k-1]+arr[1][k]);
        }
        
        cout<<max(dp[0][n-1],dp[1][n-1])<<'\n';
    }
}
