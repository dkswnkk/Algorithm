#include <string>
#include <vector>
#include <memory.h>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int>graph[20001], dists;
bool visited[20001];
int dist[20001];
int max_dist = -1;

void bfs(int start){
    queue<int>q;
    q.push(start);
    visited[start] = 1;
    
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int next: graph[x]){
            if(!visited[next]){
                dist[next] = dist[x] + 1;
                max_dist = max(dist[next] ,max_dist);
                visited[next] = 1;
                q.push(next);
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    for(int i=0; i<edge.size(); i++){
        int a = edge[i][0];
        int b = edge[i][1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    bfs(1);
    for(int i:dist){
        if(i==max_dist) answer++;
    }
    
    return answer;
}

int main(){
    cout<<solution(6, {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}});
}
