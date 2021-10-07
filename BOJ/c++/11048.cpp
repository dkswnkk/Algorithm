//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/11048
//  BOJ11048 이동하기

#include <iostream>
using namespace std;

int dp[1001][1001];
int arr[1001][1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m; cin>>n>>m;
    
    for(int i=0; i<n; i++){
        for(int k=0; k<m; k++){
            cin>>arr[i][k];
        }
    }
    dp[0][0]=arr[0][0];
    for(int i=0; i<n; i++){
        for(int k=0; k<m; k++){
            if(i==0&&k==0) continue;
            dp[i][k]=max(max(dp[i][k],dp[i-1][k]+arr[i][k]),max(dp[i][k-1]+arr[i][k],dp[i-1][k-1]+arr[i][k]));

        }
    }
    cout<<dp[n-1][m-1];
}
