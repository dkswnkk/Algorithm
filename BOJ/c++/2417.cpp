#include <iostream>
#include <cmath>
#define ll long long int
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, ans = pow(2, 63) + 1; cin>>n;
    ll start = 1, end = pow(2, 63) - 1;
    
    while(start <= end){
        ll mid = (start+end) / 2;
        if(sqrt(n) <= mid){
            ans = min(mid, ans);
            end = mid - 1;
        }
        else start = mid +1;
    }
    if(pow(ans, 2) >= n) cout<<ans;
    else cout<< ans + 1;
}
