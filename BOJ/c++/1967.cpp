#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

int max_len = 0;
int max_node;
bool visited[10001];
int ans;
vector<pair<int,int>>graph[10002];

void dfs(int node, int len){
    visited[node] = 1;
    
    if(max_len<len){
        max_len = len;
        max_node = node;
    }
    
    for(auto next: graph[node]){
        if(!visited[next.first]){
            visited[next.first] = 1;
            dfs(next.first, next.second+len);
            visited[next.first] = 0;
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N; cin>>N;
    
    for(int i=0; i<N-1; i++){
        int a,b,c; cin>>a>>b>>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    
    dfs(1, 0);
    max_len = 0;
    memset(visited,0,sizeof(visited));
    dfs(max_node, 0);
    ans += max_len;
    
    cout<<ans;
}
