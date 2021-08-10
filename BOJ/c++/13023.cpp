//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/13023
//  BOJ13023 ABCDE

#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

vector<int>graph[2001];
int visited[2001];
int N,M;    //N=사람의 수, M=친구 관계의 수
bool check;

void dfs(int start,int depth){
    visited[start]=1;
    if(depth==4){
        check=true;
        return;
    }
    else{
        for(int i=0; i<graph[start].size(); i++){
            if(!visited[graph[start][i]]) dfs(graph[start][i],depth+1); //방문 안했을때 dfs
        }
        visited[start]=0;   //이부분 안해줘서 틀림.
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N>>M;
    
    for(int i=0; i<M; i++){ //서로 친구관계면 연결.(양방향)
        int a,b; cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    for(int i=0; i<N; i++){
        dfs(i,0);
        memset(visited, 0,sizeof(visited));
    }
    
    
    if(check) cout<<1;
    else cout<<0;
}
