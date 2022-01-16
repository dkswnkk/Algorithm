#include <iostream>

using namespace std;

long long dp[51][51];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin>>n;
    
    for(int i=0; i<=n; i++){
        dp[i][0]=1;
    }
    for(int i=1; i<=n; i++){
        for(int k=1; k<=n; k++){
            dp[i][k] = dp[i-1][k-1]+dp[i-1][k];
        }
    }
    for(int i=0; i<n; i++){
        for(int k=0; k<=i; k++){
            cout<<dp[i][k]<<' ';
        }
        cout<<'\n';
    }
    
}
