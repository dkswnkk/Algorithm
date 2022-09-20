#include <iostream>
#include <vector>
#include <limits.h>

#define ll unsigned long long
using namespace std;

vector<ll> v;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N; cin>>N;
    for(int i=0; i<N; i++){
        ll inp; cin>>inp;
        v.push_back(inp);
    }

    ll start = 1, end = ULONG_LONG_MAX;
    ll ans = ULONG_LONG_MAX;
    while(start <= end){
        ll mid = start/2 + end/2;
        ll speed = mid;
        int pass_cnt = 0;
        for(int i=0; i<v.size(); i++){
            if(speed % v[i] == 0) pass_cnt++;
            else{
                if(speed > v[i]){
                    speed = v[i] * (speed / v[i]);
                    pass_cnt++;
                }
            }
        }
        if(pass_cnt >= v.size()){
            ans = min(ans, mid);
            end = mid - 1;
        }
        else start = mid + 1;
    }
    cout<<ans;
}
