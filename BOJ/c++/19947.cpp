#include <iostream>
using namespace std;

int dp[11];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    double H;
    int Y;
    cin>>H>>Y;
    
    dp[0] = H;
    for(int i=1; i<=Y; i++){
        dp[i] = dp[i-1] * 1.05;
        if(i>=3) dp[i] = max(dp[i], int(dp[i-3] * 1.2));
        if(i>=5) dp[i] = max(dp[i], int(dp[i-5] * 1.35));
    }
    cout<<dp[Y];
}
