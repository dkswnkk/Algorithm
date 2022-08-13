#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int>graph[50001];
int depth[50001];
int parent[50001];
bool visited[50001];


void dfs(int node, int _depth){
    visited[node] = 1;
    depth[node] = _depth;
    for(auto next: graph[node]){
        if(!visited[next]){
            parent[next] = node;    // 부모 세팅
            dfs(next, _depth + 1);
        }
    }
}

int lca(int a, int b){
    while(parent[a]!=parent[b]){    // 부모가 다를 경우
        if(depth[a] < depth[b]){    // 높이를 맞춰준다(높이가 긴 쪽을 적게한다.)
            b = parent[b];
        }
        else a = parent[a];
    }
    while(a!=b){
        a = parent[a];
        b = parent[b];
    }
    return a;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N;
    for(int i=0; i<N-1; i++){
        int a, b; cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1, 0); // depth 저장하기
    cin>>M;
    
    
    for(int i=0; i<M; i++){
        int a, b; cin>>a>>b;
        cout<< lca(a,b)<<'\n';
    }
}
