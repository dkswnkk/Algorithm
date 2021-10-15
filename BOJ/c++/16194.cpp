//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/16194
//  BOJ16194 카드 구매하기2

#include <iostream>
using namespace std;

int card[10001];
int dp[10001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin>>n;
    for(int i=1; i<=n; i++){
        cin>>card[i];
        dp[i]=card[i];
    }
    
    for(int i=1; i<=n; i++){
        for(int k=1; k<=i; k++){
            dp[i]=min(dp[i],card[k]+dp[i-k]);
        }
    }
    cout<<dp[n];
}
