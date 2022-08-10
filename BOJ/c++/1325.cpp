#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

int N, M, max_hacking_cnt, hacking_cnt = 1;
vector<int>graph[10001];
vector<pair<int,int>>_depth;
bool visited[10001];

void dfs(int node){
    visited[node] = 1;
    
    for(auto next: graph[node]){
        if(!visited[next]){
            hacking_cnt++;
            dfs(next);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N>>M;
    for(int i=0; i<M; i++){
        int a, b; cin>>a>>b;
        graph[b].push_back(a);  // a가 b를 신뢰한다.
    }
    
    for(int i=1; i<=N; i++){
        dfs(i);
        _depth.push_back({i, hacking_cnt});
        max_hacking_cnt = max(max_hacking_cnt, hacking_cnt);
        hacking_cnt = 1;
        memset(visited,0,sizeof(visited));
    }
    sort(_depth.begin(), _depth.end());
    
    for(int i=0; i<_depth.size(); i++){
        if(_depth[i].second == max_hacking_cnt){
            cout<< _depth[i].first <<' ';
        }
    }
    
}
