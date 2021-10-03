//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/9251
//  BOJ9251 LCS

#include <iostream>
using namespace std;

int dp[1001][1001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string A,B; cin>>A>>B;
    
    for(int i=1; i<=A.length(); i++){
        for(int k=1; k<=B.length(); k++){
            if(A[i-1]==B[k-1]) dp[i][k]=dp[i-1][k-1]+1;
            else dp[i][k]=max(dp[i-1][k],dp[i][k-1]);
            
        }
    }
    cout<<dp[A.length()][B.length()];
}
