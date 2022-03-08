#include <iostream>
#include <vector>
#include <memory.h>


#define MAX 1e9
using namespace std;


int N,M;
vector<pair<int,int>>graph[1001];
int visited[1001];

int ans;

void dfs(int x, int y, int dist){
    visited[x]=1;
    
    if(x==y){
        ans = dist;
        return;
    }
    
    for(int i=0; i<graph[x].size(); i++){
        int cost = dist + graph[x][i].second;
        int next_node = graph[x][i].first;
        if(visited[next_node]) continue;
        visited[next_node]=1;
        dfs(graph[x][i].first, y, cost) ;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N>>M;
    
    for(int i=0; i<N-1; i++){
        int a,b,dist; cin>>a>>b>>dist;
        graph[a].push_back({b,dist});
        graph[b].push_back({a,dist});
    }
    
    
    for(int i=0; i<M; i++){
        int a,b; cin>>a>>b;
        dfs(a,b,0);
        memset(visited,0,sizeof(visited));
        cout<<ans<<'\n';
    }
    
}
