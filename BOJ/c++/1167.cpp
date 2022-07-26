#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;
vector<pair<int,int>> graph[100001];

int max_len = 0, max_node;
bool visited[100001];

void find_max_len(int node, int len){
    visited[node] = true;
    if(len>max_len){
        max_node = node;
        max_len = len;
    }
    
    for(auto next: graph[node]){
        if(!visited[next.first]){
            visited[next.first] = true;
            find_max_len(next.first, len + next.second);
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int V; cin>>V;
    
    for(int i=0; i<V; i++){
        int node_a = 0, node_b, cost;
        for(int k=0;; k++){
            if(k==0) cin>>node_a>>node_b>>cost;
            else{
                cin>>node_b;
                if(node_b == -1) break;
                cin>>cost;
            }
            graph[node_a].push_back({node_b, cost});
        }
    }
    
    find_max_len(1, 0);
    memset(visited, 0 ,sizeof(visited));
    max_len = 0;
    find_max_len(max_node, 0);
    
    
    cout<<max_len;
}
