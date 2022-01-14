#include <iostream>
#include <vector>

using namespace std;

int N,M,ans;
int visited[101];
vector<int>v[101];

void dfs(int start){
    visited[start]=1;
    ans++;
    for(int i=0; i<v[start].size(); i++){
        if(visited[v[start][i]]) continue;
        dfs(v[start][i]);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    
    cin>>N>>M;
    for(int i=0; i<M; i++){
        int a,b; cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    cout<<ans-1;
}
