#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T; cin>>T;
    while(T--){
        int n , m; cin>>n>>m;
        vector<int>arr(n), dp(n);
        for(int i=0; i<n; i++) cin>>arr[i];
        sort(arr.begin(),arr.end(),greater<>());
        dp[0] = arr[0];
        for(int i=1; i<n; i++) dp[i] = dp[i-1]+ arr[i];
        
        for(int k=0; k<m; k++){
            int target; cin>>target;
            int ans = lower_bound(dp.begin(), dp.end(), target) - dp.begin();
            
            if(ans+1>n) ans = -1;
            else ans = ans+1;
            cout<<ans<<'\n';
        }
        
    }
}
