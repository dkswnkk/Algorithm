//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/3067
//  BOJ3067 Coins

#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t; cin>>t;
    
    while(t--){
        int n,m; cin>>n;
        vector<int>coin(n+1);
        for(int i=1; i<=n; i++){
            cin>>coin[i];
        }
        cin>>m;
        vector<int>dp(m+1);
        dp[0]=1;
        for(int i=1; i<=n; i++){
            for(int j=coin[i]; j<=m; j++){
                dp[j]+=dp[j-coin[i]];
            }
        }
        cout<<dp[m]<<'\n';
    }
}
