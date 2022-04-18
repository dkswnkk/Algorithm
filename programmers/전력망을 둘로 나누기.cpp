#include <string>
#include <vector>
#include <memory.h>
#include <iostream>

using namespace std;

vector<int>graph[101];
vector<pair<int,int>>divide;
bool visited[101];
int group_cnt;
int node_cnt[2];

void dfs(int node, pair<int,int> cut){
    visited[node] = 1;
    node_cnt[group_cnt]++;
    for(int i=0; i<graph[node].size(); i++){
        int next = graph[node][i];
        if((node==cut.first&&next==cut.second)||(node==cut.second&&next==cut.first)) continue;
        if(visited[next]) continue;
        dfs(next, cut);
    }
}
int solution(int n, vector<vector<int>> wires) {
    int answer = 1e9;
    
    for(int i=0; i<wires.size(); i++){
        int a = wires[i][0];
        int b = wires[i][1];
        graph[a].push_back(b);
        graph[b].push_back(a);
        divide.push_back({a,b});
    }
    
    for(int i=0; i<divide.size(); i++){
        int a = divide[i].first;
        int b = divide[i].second;
        
        for(int k=1; k<=wires.size(); k++){
            if(visited[k]) continue;
            dfs(k, {a,b});
            group_cnt++;
        }
        
        if(group_cnt==2) answer = min(answer, abs(node_cnt[0]-node_cnt[1]));   //두개로 분할 되었을 때
        group_cnt = 0;
        memset(visited, 0, sizeof(visited));
        node_cnt[0] = 0, node_cnt[1] = 0;
    }
    
    return answer;
}
