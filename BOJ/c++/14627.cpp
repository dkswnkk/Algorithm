#include <iostream>
#include <vector>

#define ll long long int
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ll S, C; cin>>S>>C;
    vector<ll> v(S);
    for(int i=0; i<S; i++) cin>>v[i];
    
    ll start = 1, end = 1e9;
    ll mod = 0, sum = 0;
    
    while(start <= end){
        ll mid = (start + end) / 2;
        ll sum = 0;
        for(int i=0; i<v.size(); i++){
            if(v[i] >= mid) sum += v[i] / mid;
        }
        if(sum >= C){
            mod = mid;
            start = mid + 1;
        }
        else end = mid - 1;
    }
    
    for(int i=0; i<v.size(); i++) sum += v[i];
    cout<< sum - mod * C;
}
