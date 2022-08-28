#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

vector<int> graph[100001];
bool visited[100001];
int parent[100001][21];
int depth[100001];
int N, M, max_height;


void dfs(int node, int _depth){ // 노드 깊이 세팅
    visited[node] = 1;
    depth[node] = _depth;
    for(auto next: graph[node]){
        if(visited[next]) continue;
        parent[next][0] = node; // 한 칸 위의 조상 저장
        dfs(next, _depth+1);
    }
}

void parent_set(){  // 전체 부모 세팅
    for(int i=1; i<max_height; i++){   // max height
        for(int k=1; k<=N; k++){
            if(parent[k][i-1] != 0){
                parent[k][i] = parent[parent[k][i-1]][i-1];
            }
        }
    }
}

int lca(int a, int b){
    
    if(depth[a] > depth[b]) swap(a,b);  // b의 노드의 깊이가 더 깊게 만들어준다.
    
    
    for(int i=max_height; i>=0; i--){   // depth가 같도록 세팅
        int diff = depth[b] - depth[a]; // 두 노드의 깊이 차
        if(diff >= (1<<i)) b = parent[b][i];
    }
    
    if(a == b) return a;
    
    for(int i=max_height; i>=0; i--){   // 조상을 향해 거슬러 올라가기
        if(parent[a][i] != parent[b][i]){
            a = parent[a][i];
            b = parent[b][i];
        }
    }
    return parent[a][0];
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
    
    int temp = N;
    while(temp>0){
        max_height++;
        temp = temp>>1;
    }
    dfs(1,0);
    parent_set();

    cin>>M;
    for(int i=0; i<M; i++){
        int a, b; cin>>a>>b;
        cout<<lca(a,b)<<'\n';
    }
}
