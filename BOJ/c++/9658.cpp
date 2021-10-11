//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/9658
//  BOJ9658 돌 게임4

#include <iostream>
using namespace std;

int dp[1001];

void game(int cnt){
    if(dp[cnt]!=0) return;
    if(cnt==1||cnt==3){
        dp[cnt]=-1;
        return;
    }
    for(int i=1; i<=4; i++){
        if(i==2) continue;
        if(cnt-i>=0){
            if(dp[cnt-i]==0) game(cnt-i);
            if(dp[cnt-i]==-1){
                dp[cnt]=1;
                return;
            }
        }
    }
    dp[cnt]=-1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin>>n;
    
    game(n);
    if(dp[n]==1) cout<<"SK";
    else cout<<"CY";
}
