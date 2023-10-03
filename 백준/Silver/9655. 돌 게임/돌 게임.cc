#include <iostream>
using namespace std;


int dp[1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N; cin>>N;
    
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    
    for(int i=3; i<=N; i++){
        dp[i] = min(dp[i-1] + 1, dp[i-3] + 1);
    }
    
    if(dp[N] % 2 == 0){
        cout<<"CY";
    }
    else{
        cout<<"SK";
    }
}
