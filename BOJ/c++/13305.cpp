// 17점까지 28분
// 100점까지 65분

#include <iostream>
#include <vector>
#define ull unsigned long long

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ull N; cin>>N;
    ull ans = 0, min_cost = 1e9+1;
    vector<ull> cost(N);
    vector<ull> dist(N-1);
    
    for(int i=0; i<N-1; i++) cin>>dist[i];
    for(int i=0; i<N; i++) cin>>cost[i];
    
    for(int i=0; i<N-1; i++){
        min_cost = min(cost[i],min_cost);
        ans += min_cost * dist[i];
    }
    
    cout<<ans;

    
}
