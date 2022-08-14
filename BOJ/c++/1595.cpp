#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

vector<pair<int,int>>graph[10001];
bool visited[10001];
int max_cost, max_node;

void dfs(int node, int cost){
    if(cost>max_cost){
        max_cost = cost;
        max_node = node;
    }
    visited[node] = 1;
    for(auto next: graph[node]){
        if(!visited[next.first]){
            dfs(next.first, cost + next.second);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int a, b, c;
    while(cin>>a>>b>>c){
        graph[a].push_back({b,c});  //a에서 b까지 가는데 c만큼의 비용이 든다.
        graph[b].push_back({a,c});
    }
    
    dfs(1,0);
    memset(visited, 0, sizeof(visited));
    max_cost = 0;
    dfs(max_node, 0);
    cout<<max_cost;
}
