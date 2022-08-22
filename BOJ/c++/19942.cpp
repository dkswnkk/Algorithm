#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int mp,mf,ms,mv;

struct Info{
    int p;  // 단백질
    int f;  // 지방
    int s;  // 탄수화물
    int v;  // 비타민
    int c;  // 비용
};
vector<Info>v;
vector<pair<int, vector<int>>>ans;
bool visited[16];

int min_cost = 1e9;


void backtracking(int idx, Info info, vector<int> ingredient){
    
    if(info.p>= mp && info.f>= mf && info.s>=ms && info.v >= mv){
        if(min_cost >= info.c){
            min_cost = info.c;
            ans.push_back({min_cost, ingredient});
            return;
        }
    }
    
    for(int i=idx; i<N; i++){
        if(visited[i]) continue;
        visited[i] = 1;
        info.p += v[i].p;
        info.f += v[i].f;
        info.s += v[i].s;
        info.v += v[i].v;
        info.c += v[i].c;
        ingredient.push_back(i+1);
        backtracking(i+1, info, ingredient);
        ingredient.pop_back();
        info.p -= v[i].p;
        info.f -= v[i].f;
        info.s -= v[i].s;
        info.v -= v[i].v;
        info.c -= v[i].c;
        visited[i] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N;
    cin>>mp>>mf>>ms>>mv;
    for(int i=0; i<N; i++){
        int _a, _b, _c, _d, _e; cin>>_a>>_b>>_c>>_d>>_e;
        v.push_back({_a,_b,_c,_d,_e});
    }
    
    backtracking(0, {0,0,0,0,0}, {});
    
    if(ans.empty()){
        cout<<-1;
        return 0;
    }
    cout<<min_cost<<'\n';
    sort(ans.begin(), ans.end());

    for(int i: ans[0].second) cout<<i<<' ';
}
