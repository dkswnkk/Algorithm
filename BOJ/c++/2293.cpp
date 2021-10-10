//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/2293
//  BOJ2293 동전 1

#include <iostream>
using namespace std;

int dp[10001];
int coin[10001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,k; cin>>n>>k;
    
    for(int i=1; i<=n; i++){
        cin>>coin[i];
    }
    dp[0]=1;
    for(int i=1 ; i<=n; i++){
        for(int j=coin[i]; j<=k; j++){
            dp[j]+=dp[j-coin[i]];
        }
    }
    cout<<dp[k];
}
