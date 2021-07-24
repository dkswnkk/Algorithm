#include <string>
#include <vector>

using namespace std;

int n1,n2,answer;
int visited[201];
int graph[201][201];

void dfs(int x){
    visited[x]=1;
    
    for(int i=0; i<n1; i++){
        if(!visited[i]&&graph[x][i]){
            visited[i]=1;
            dfs(i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    
    n1=n;
    n2=computers[0].size();
    for(int i=0; i<n1; i++){
        for(int k=0; k<n2; k++){
            graph[i][k]=computers[i][k];
            graph[k][i]=computers[k][i];
        }
    }
    for(int i=0; i<n; i++){
        if(!visited[i]){
            dfs(i);
            answer++;
        }
    }    
    return answer;
}
