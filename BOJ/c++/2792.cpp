#include <iostream>
#include <vector>
#define ll unsigned long long int
using namespace std;

int N, M;
vector<ll> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N>>M;
    ll max_find = 0;
    for(int i=0; i<M; i++){
        int inp; cin>>inp;
        v.push_back(inp);
        max_find += inp;
    }
    
    ll start = 1, end = max_find;
    ll ans = 0;
    while(start <= end){
        ll mid = (start + end) / 2;
        ll jeal = mid;  // 최대 질투심
        ll peo = 0;
        for(int i=0; i<M; i++){
            if(jeal >= v[i]) peo += 1;
            else{
                if(v[i] % jeal == 0) peo += v[i] / jeal;
                else peo += (v[i] / jeal) + 1;
            }
        }
        if(peo > N) start = mid +1;
        else{
            ans = mid;
            end = mid -1;
        }
    }
    cout<<ans;
    
}
