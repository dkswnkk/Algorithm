#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N; cin>>N;
    vector<int>v,dp(N);
    
    for(int i=0; i<N; i++){
        int inp; cin>>inp;
        v.push_back(inp);
    }
    
    int ans = 0;
    
    for(int i=1; i<N-1; i++){
        dp[i]=v[i]+min(v[i-1],v[i+1]);
        ans = max(ans,dp[i]);
    }
    ans = max(ans, v[0]);
    ans = max(ans, v.back());
    cout<<ans;
}
