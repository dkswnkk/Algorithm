#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        vector<int>v(n);
        int min_v = 1e9;
        int ans = 0;
        for(int i=0; i<n; i++){
            cin>>v[i];
            min_v = min(v[i],min_v);
        }
        for(int i:v) ans += (i-min_v);
        cout<<ans<<'\n';
    }
}
