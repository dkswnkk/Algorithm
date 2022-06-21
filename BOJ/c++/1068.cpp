#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

vector<int>v[51];
bool visited[51];
int N, root;
int cnt;

void dfs(int start){
    if(v[start].empty()){
        cnt++;
        return;
    }
    else if(v[start].size()==1){
        if(visited[v[start].front()] == true) cnt++;
    }
    
    for(auto it: v[start]){
        if(!visited[it]){
            visited[it] = true;
            dfs(it);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N;
    for(int i=0; i<N; i++){
        int node; cin>>node;
        if(node==-1) root = i;
        else if(node!=-1) v[node].push_back(i);
    }
    memset(visited,0,sizeof(visited));
    int remove; cin>>remove;
    
    visited[remove] = true;
    if(remove!=root) dfs(root);
    cout<<cnt;
}
