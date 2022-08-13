#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int>graph[100001];
int depth[100001];
int N, S, D, ans = 0;


int dfs(int node, int before){
    for(auto next: graph[node]){
        if(next != before){
            depth[node] = max(depth[node], dfs(next, node)+1);  // 각 노드의 깊이 자손들 중 가장 깊은 노드의 깊이를 알 수 있음
        }
    }
    if(depth[node]>=D && node != S) ans++;
    return depth[node];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N>>S>>D;
    for(int i=0; i<N-1; i++){
        int a,b; cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    dfs(S, -1);
    
    cout<<ans*2;
    
}
