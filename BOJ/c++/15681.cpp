#include <iostream>
#include <vector>

using namespace std;

int N, R, Q;
int max_depth = -1, max_node;
vector<int>graph[100001];
int subnode_cnt[100001];

int dfs(int node, int before){
    for(auto next: graph[node]){
        if(next != before){
            subnode_cnt[node] += dfs(next, node)+1;
        }
    }
    return subnode_cnt[node];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>R>>Q;
    for(int i=0; i<N-1; i++){
        int a,b; cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(R, 0);
    
    for(int i=0; i<Q; i++){
        int q; cin>>q;
        cout<<subnode_cnt[q]+1<<'\n';
    }
}
