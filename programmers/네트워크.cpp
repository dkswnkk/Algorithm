#include <string>
#include <vector>

using namespace std;


void dfs(int x){

}

int graph[101][101];
int visited[101];

void dfs(int start, int n){
    visited[start]=1;
    for(int i=0; i<n; i++){
        if(graph[start][i]){
            if(!visited[i]) dfs(i, n);
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0; i<computers.size(); i++){
       for(int k=0; k<n; k++){
           if(computers[i][k]]){
               graph[i][k] = 1;
               graph[k][i] = 1;
           }
       }
    }
    
    for(int i=0; i<n; i++){
        if(!visited[i]) answer++;
        dfs(i, n);
    }
    return answer;
}
