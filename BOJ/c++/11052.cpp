//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/11052
//  BOJ11052 카드 구매하기

#include <iostream>
using namespace std;

int dp[10001];
int card[10001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin>>n;
    for(int i=1; i<=n; i++){
        cin>>card[i];
    }
    //card[]의 index=갯수, value= 가격
    for(int i=1; i<=n; i++){
        for(int k=1; k<=i; k++){
            dp[i]=max(dp[i],dp[i-k]+card[k]);
        }
    }
    cout<<dp[n];
}
