//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/15482
//  BOJ15482 한글 LCS

#include <iostream>
using namespace std;

int dp[3001][3001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string A,B; cin>>A>>B;
    
    for(int i=3; i<=A.length(); i+=3){
        for(int k=3; k<=B.length(); k+=3){
            if(A.substr(i-3,3)==B.substr(k-3,3)) dp[i][k]=dp[i-3][k-3]+1;
            else dp[i][k]=max(dp[i-3][k],dp[i][k-3]);
            
        }
    }
    cout<<dp[A.length()][B.length()];
}
