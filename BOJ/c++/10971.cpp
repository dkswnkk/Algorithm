#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

int N, min_cost = 1e9;
int graph[11][11];
int visited[11];


void dfs(int start, int node, int cost, int depth){\
    if(depth == N && node == start){
        min_cost = min(min_cost, cost + graph[node][start]);
        return;
    }
    for(int i=0; i<N; i++){
        if(!visited[i] && graph[node][i] && cost<min_cost){
            visited[i] = 1;
            dfs(start, i, cost+graph[node][i], depth + 1);
            visited[i] = 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N;
    
    for(int i=0; i<N; i++){
        for(int k=0; k<N; k++){
            cin>>graph[i][k];
        }
    }
    
    for(int i=0; i<N; i++){
        dfs(i, i, 0, 0);
        memset(visited, 0 ,sizeof(visited));
    }
    cout<<min_cost;
}
