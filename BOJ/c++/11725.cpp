//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/11725
//  BOJ11725 트리의 부모 찾기

#include <iostream>
#include <vector>
using namespace std;

vector<int>graph[100001];
int visited[100001];
int tracking[100001];

void dfs(int x){
    visited[x]=1;
    for(int i=0; i<graph[x].size(); i++){
        if(!visited[graph[x][i]]){
            visited[graph[x][i]]=1;
            dfs(graph[x][i]);
            tracking[graph[x][i]]=x;
            
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N; cin>>N;
    
    for(int i=0; i<N-1; i++){
        int a,b; cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=1; i<=N; i++){
        dfs(i);
    }
    for(int i=2; i<=N; i++){
        cout<<tracking[i]<<'\n';
    }
}
