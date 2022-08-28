#include <iostream>
#include <vector>
#define MAX 40001
using namespace std;

int N, M, max_height;
int depth[MAX];
vector<pair<int,int>>graph[MAX];
bool visited[MAX];
int parent[MAX][30];
int dist[MAX][30];

void dfs(int node, int _depth){
    visited[node] = 1;
    depth[node] = _depth;
    for(auto next: graph[node]){
        if(visited[next.first]) continue;
        parent[next.first][0] = node;
        dist[next.first][0] = next.second;
        dfs(next.first, _depth+1);
    }
}

void set_parent(){
    for(int i = 1; i<max_height; i++){
        for(int k=1; k<=N; k++){
            int prev_parent = parent[k][i-1];
            parent[k][i] = parent[prev_parent][i-1];
            if(parent[prev_parent][i-1] == 0) continue;
            dist[k][i] = dist[k][i-1] + dist[prev_parent][i-1];
        }
    }
}

int lca(int a, int b){
    int _dist = 0;
    if(depth[a] > depth[b]) swap(a, b);

    for(int i=max_height; i>=0; i--){   // 깊이 맞추기
        int diff = depth[b] - depth[a];
        int jump = 1 << i;
        if(jump <= diff){
            _dist += dist[b][i];
            b = parent[b][i];
        }
    }

    if(a == b) return _dist;

    for(int i=max_height; i>=0; i--){   // 조상을 향해 올라가기
        if(parent[a][i] != parent[b][i]){
            _dist += dist[a][i];
            a = parent[a][i];
            _dist += dist[b][i];
            b = parent[b][i];
        }
    }

    _dist += dist[a][0] + dist[b][0];
    return _dist;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N;
    int temp = N;
    
    while(temp>0){
        max_height++;
        temp = temp >> 1;
    }
    
    for(int i=0; i<N-1; i++){
        int a, b, c; cin>>a>>b>>c;
        graph[a].push_back({b,c});  // a 에서 b로 가는데 c까지의 거리
        graph[b].push_back({a,c});  // 양 방향 연결
    }
    
    dfs(1, 0);
    set_parent();
    cin>>M;
    for(int i=0; i<M; i++){
        int a, b; cin>>a>>b;
        cout<<lca(a, b)<<'\n';
    }
    
}
