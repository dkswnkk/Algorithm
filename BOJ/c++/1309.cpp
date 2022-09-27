#include <iostream>
#define MOD 9901
using namespace std;

int dp[100001][3];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    dp[0][0] = 1;   // 사자를 놓지않는 경우
    dp[0][1] = 1;   // 사자를 왼쪽에 배치하는 경우
    dp[0][2] = 1;   // 사자를 오른쪽에 배치하는 경우z
    
    int N; cin>>N;
    for(int i=1; i<N; i++){
        dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2]) % MOD;
        dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % MOD;
        dp[i][2] = (dp[i-1][0] + dp[i-1][1]) % MOD;
    }
    cout<<(dp[N-1][0] + dp[N-1][1] + dp[N-1][2]) % MOD;
}
