#include <iostream>
#include <vector>

using namespace std;

vector<int>graph[100001];
int point[100001];

void add_point(int node, int _point){
    
    point[node] += _point;
    
    for(auto next: graph[node]){
        add_point(next, point[node]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m; cin>>n>>m;
    for(int i=1; i<=n; i++){
        int inp; cin>>inp;
        if(inp==-1) continue;
        graph[inp].push_back(i);
    }
    
    for(int i=0; i<m; i++){
        int peo, cost; cin>>peo>>cost;
        point[peo] += cost;  // peo: 직원번호, cost: 칭찬정도
    }
    
    add_point(1, point[1]);
    
    for(int i=1; i<=n; i++){
        cout<<point[i]<<' ';
    }
}
