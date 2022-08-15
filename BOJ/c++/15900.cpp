#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int>graph[500001];
bool visited[500001];
int odd_height_cnt;

void dfs(int node, int depth){
    if(graph[node].size()==1 && node != 1){  // 리프노드일 때
        if(depth&1) odd_height_cnt++;
        return;
    }
    visited[node] = 1;
    for(auto next: graph[node]){
        if(!visited[next]){
            dfs(next, depth+1);
        }
    }
}
int main(){
    
    /*
     높이가 홀수인 리프노드가 홀수개면 이기고 짝수개면 진다.
     */
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N;
    for(int i=0; i<N-1; i++){
        int a,b; cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    dfs(1, 0);
    
    if(odd_height_cnt % 2 == 0) cout<<"No";
    else cout<<"Yes";
}
