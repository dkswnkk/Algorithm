//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/1932
//  BOJ1932 정수 삼각형

#include <iostream>
using namespace std;

int arr[501][501];
int dp[501][501];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin>>n;
    for(int i=0; i<n; i++){ //inp
        for(int zero=0; zero<n; zero++){
            arr[i][zero]=0;
        }
        for(int k=0; k<=i; k++){
            cin>>arr[i][k];
        }
    }
    dp[0][0]=arr[0][0];
    int ans=dp[0][0];
    for(int i=1; i<n; i++){
        for(int k=0; k<=i; k++){
            dp[i][k]=max(dp[i-1][k]+arr[i][k],dp[i-1][k-1]+arr[i][k]);
            ans=max(dp[i][k],ans);
        }
    }
    
    cout<<ans;
}


===================2022.04.04===================
#include <iostream>

using namespace std;

int arr[501][501];
int dp[501][501];
int ans;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N; cin>>N;
    for(int i=1; i<=N; i++){
        for(int k=0; k<i; k++){
            cin>>arr[i-1][k];
        }
    }
    dp[0][0] = arr[0][0];
    ans = dp[0][0];
    
    for(int i=1; i<N; i++){
        for(int k=0; k<N; k++){
            if(k==0) dp[i][k] = dp[i-1][k] + arr[i][k];
            else if(k==N-1) dp[i][k] = dp[i-1][k-1] + arr[i][k];
            else dp[i][k] = max(dp[i-1][k-1]+arr[i][k],dp[i-1][k]+arr[i][k]);
            ans = max(ans, dp[i][k]);
        }
    }
    cout<<ans;
    
}
