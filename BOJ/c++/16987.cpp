#include <iostream>
#include <vector>
using namespace std;

int N, ans, temp_cnt;
vector<pair<int,int>>v;

void backtracking(int idx){
    if(idx == N+1) return;
    
    for(int i=0; i<N; i++){
        if(v[idx].first<=0) backtracking(idx+1);
        else if(v[i].first<=0 || i==idx) continue;
        else{
            v[idx].first -= v[i].second;
            v[i].first -= v[idx].second;
            backtracking(idx+1);
            v[idx].first += v[i].second;
            v[i].first += v[idx].second;
        }
    }
    
    for(int i=0; i<N; i++){
        if(v[i].first<=0) temp_cnt++;
    }
    ans = max(ans, temp_cnt);
    temp_cnt = 0;
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N;
    for(int i=0; i<N; i++){
        int a, b; cin>>a>>b;
        v.push_back({a,b}); // {내구도, 무게}
    }
    
    
    backtracking(0);
    
    cout<<ans;
}
