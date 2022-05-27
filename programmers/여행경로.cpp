#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

struct Info{
    string city;
    int index;
};

unordered_map<string, vector<Info>>graph;
bool flag = true;
vector<string>answer;
int visited[10001];

void dfs(string now, int move, vector<string>memory, int len){
    if(move == len&&flag){
        flag = false;
        answer = memory;
        return;
    }
    
    for(int i=0; i<graph[now].size(); i++){
        if(visited[graph[now][i].index]) continue;
        visited[graph[now][i].index] = 1;
        memory.push_back(graph[now][i].city);
        dfs(graph[now][i].city, move+1, memory, len);
        memory.pop_back();
        visited[graph[now][i].index] = 0;
    }
}
vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    
    for(int i=0; i<tickets.size(); i++){
        string a = tickets[i][0];
        string b = tickets[i][1];
        graph[a].push_back({b,i});
    }
    
    dfs("ICN", 0, {"ICN"}, tickets.size());
    
    return answer;
}
