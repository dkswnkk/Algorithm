//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/9084
//  BOJ9084 동전

#include <iostream>
#include <vector>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T; cin>>T;
    while(T--){
        int n,m; cin>>n;
        vector<int>coin(n+1,0);
        for(int i=1; i<=n; i++){
            cin>>coin[i];
        }
        cin>>m;  //만들어야 할 금액
        vector<int>dp(m+1,0);
        dp[0]=1;
        for(int i=1; i<=n; i++){
            for(int j=coin[i]; j<=m; j++){
                dp[j]+=dp[j-coin[i]];
            }
        }
        cout<<dp[m]<<'\n';
    }
}
