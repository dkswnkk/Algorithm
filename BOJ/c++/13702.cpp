#include <iostream>
#include <vector>
#define ll long long int
using namespace std;

vector<ll> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ll N, K, ans = 0; cin>>N>>K;
    ll max_ml = 0;
    for(int i=0; i<N; i++){
        ll inp; cin>>inp;
        v.push_back(inp);
        max_ml = max(max_ml, inp);
    }
    
    if(max_ml == 0){
        cout<<0;
        return 0;
    }
    
    ll start = 1, end = max_ml;
    while(start <= end){
        ll peo = 0;
        ll mid = (start + end) / 2;
        ll div = mid;
        for(int i=0; i < v.size(); i++){
            if(div <= v[i]) peo += v[i] / div;
        }
        if(peo >= K){
            ans = max(ans, div);
            start = mid + 1;
        }
        else end = mid - 1;
    }
    cout<<ans;

}
