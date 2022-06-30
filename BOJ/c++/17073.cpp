#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<vector<int>>graph;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N,W; cin>>N>>W;
    graph.resize(N+1);
    for(int i=0; i<N-1; i++){
        int a, b; cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    int leaf_cnt = 0;
    for(int i=2; i<=N; i++){
        if(graph[i].size()<2) leaf_cnt++;
    }
    
    cout.precision(10);
    cout<<fixed<<W*1.0/leaf_cnt;
}
