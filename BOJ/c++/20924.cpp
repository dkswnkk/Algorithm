#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

vector<pair<int,int>>tree[200001];
bool visited[200001];
int trunk_len, start_branch, branch_len, end_branch;

void find_trunk(int node, int len){
    visited[node] = true;
    trunk_len = len;
    start_branch = node;
    if(tree[node].size()>2) return;
    
    for(auto next: tree[node]){
        if(!visited[next.first]){
            visited[next.first] = true;
            find_trunk(next.first,len+next.second);
        }
    }
}

void find_branch(int node, int len){
    visited[node] = true;
    if(len>branch_len){
        end_branch = node;
        branch_len = len;
    }
    
    for(auto next: tree[node]){
        if(!visited[next.first]){
            visited[next.first] = true;
            find_branch(next.first,len+next.second);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, R; cin>>N>>R;
    
    for(int i=0; i<N-1; i++){
        int a, b, c; cin>>a>>b>>c;
        tree[a].push_back({b,c});
        tree[b].push_back({a,c});
    }
    if(tree[R].size()>=2){
        find_trunk(R, 0);
        trunk_len = 0;
        memset(visited, 0, sizeof(visited));
        find_branch(R, 0);
    }
    else{
        find_trunk(R, 0);
        find_branch(start_branch, 0);
    }

    cout<<trunk_len<<' '<<branch_len;
     
}
