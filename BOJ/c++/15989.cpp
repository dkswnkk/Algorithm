#include <iostream>
using namespace std;

int dp[10001][4];   // dp[i][j] = {i를 만들 때 마지막으로 더한 수가 j인 경우의 수}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    dp[1][1] = 1; // 1
    dp[2][1] = 1, dp[2][2] = 1; // 1+1, 2
    dp[3][1] = 1, dp[3][2] = 1, dp[3][3] = 1;   // 1+1+1, 1+2, 3
    
    int N; cin>>N;
    while(N--){
        int n; cin>>n;
        for(int i=4; i<=n; i++){
            dp[i][1] = dp[i-1][1];
            dp[i][2] = dp[i-2][1] + dp[i-2][2];
            dp[i][3] = dp[i-3][1] + dp[i-3][2] + dp[i-3][3];
        }
        cout<<dp[n][1] + dp[n][2] + dp[n][3]<<'\n';
    }
}
