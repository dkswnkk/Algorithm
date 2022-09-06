#include <iostream>
#include <cmath>
#define ll unsigned long long int
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T; cin>>T;
    while(T--){
        ll n; cin>>n;
        ll start = 1, end = 1e16;
        ll ans = 0;
        while(start <= end){
            ll mid = (start + end) / 2;
            if(mid * (mid+1) <= 2*n){
                ans = max(ans, mid);
                start = mid+1;
            }
            else end = mid - 1;
        }
        cout<<ans<<'\n';
    }
}
