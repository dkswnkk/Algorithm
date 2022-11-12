#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        vector<ll> v(n);
        for(int i=0; i<n; i++) cin>>v[i];
        
        ll len = v.size()-1;
        ll pivot = -1;
        ll ans = 0;
        for(int i = len; i>=0; i--){
            if(pivot==-1) pivot = v[i];
            else{
                if(v[i] < pivot){
                    ans += pivot - v[i];
                }
                else pivot = v[i];
            }
        }
        cout<<ans<<'\n';
    }
}
