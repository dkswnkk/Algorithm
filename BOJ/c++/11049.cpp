//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnzz
//  https://www.acmicpc.net/problem/11049
//  BOJ11049 행렬 곱셈 순서

#include <iostream>
#define INF 1e9


/*
 (i<=k<=j-1)
 dp[i][j]=min(dp[i][k]+dp[k+1][j]+d[i-1]*d[k]*d[j])
 */

int dp[501][501];
int r[501],c[501];
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N; cin>>N;
    
    for (int i=0; i<N; i++){
        dp[i][i]=0;
    }
    
    for(int i=0; i<N; i++){
        cin>>r[i]>>c[i];
    }
    
    for(int cnt=1; cnt<N; cnt++){
        for(int i=0; i<=N-cnt; i++){
            int j=i+cnt;
            dp[i][j]=INF;
            for(int k=i; k<j; k++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+r[i]*r[k+1]*c[j]);
            }
        }
    }
    cout<<dp[0][N-1];
}

