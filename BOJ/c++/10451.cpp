//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/10451
//  BOJ10451 순열 사이클

#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

int graph[1001];
int visited[1001];
bool check;

void dfs(int start,int next){
    visited[start]=1;
    visited[next]=1;
    if(next==start){
        check= true;
        return;
    }
    else{
        dfs(start,graph[next]);
    }
    
}

int main(){
    
    int T; cin>>T;
    while(T--){
        int ans=0;
        int N; cin>>N;
        
        for(int i=1; i<=N; i++){
            cin>>graph[i];
        }
        for(int i=1; i<=N; i++){
            if(!visited[i])dfs(i,graph[i]);
            if(check){
                ans++;
                check=false;
            }
        }
        cout<<ans<<'\n';
        memset(visited, 0, sizeof(visited));
    }
    
}
