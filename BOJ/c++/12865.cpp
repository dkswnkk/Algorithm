//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnzz
//  https://www.acmicpc.net/problem/12865
//  BOJ12865 평범한 배낭

#include <iostream>
using namespace std;

int dp[101][100001];
int w[101];
int v[100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N,K;    // N: 물품의 수, K: 배낭의 최대 무게
    cin>>N>>K;
    
    for(int i=1; i<=N; i++){
        cin>>w[i]>>v[i];
    }
    
    for(int i=1; i<=N; i++){
        for(int k=1; k<=K; k++){
            if(k-w[i]>=0) dp[i][k]=max(dp[i-1][k],v[i]+dp[i-1][k-w[i]]);
            else dp[i][k] = dp[i-1][k];
        }
    }
    cout<<dp[N][K];
}
