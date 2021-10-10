//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/2294
//  BOJ2294 동전2

#include <iostream>
#include <algorithm>
#define INF 2e9

using namespace std;

int coin[101];
int dp[100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,k; cin>>n>>k;
    
    fill(dp, dp+100001, INF);
    
    for(int i=1; i<=n; i++){
        cin>>coin[i];
        dp[coin[i]]=1;
    }
    
    dp[0]=0;
    
    for(int i=1; i<=n; i++){
        for(int j=coin[i]; j<=k; j++){
            dp[j]=min(dp[j],dp[j-coin[i]]+1);
        }
    }
    if (dp[k]==2e9) cout <<-1;
    else cout<<dp[k];
}
