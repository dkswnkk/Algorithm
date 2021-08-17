//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/13913
//  BOJ13913 숨바꼭질4

#include <iostream>
#include <queue>
#define MAX 100001

using namespace std;


int N,K;    //N=수빈이가 있는 위치, K=동생이 있는 위치
int visited[MAX];
int sec=MAX;
vector<int>path_print;
int path_memory[MAX];

void bfs(int start,int time){
    queue<pair<int,int>>q;
    q.push({start,0});
    visited[start]=1;
    
    while(!q.empty()){
        int start=q.front().first;
        int time=q.front().second;
        q.pop();
        
        
        if(start==K){
            sec=time;
            int path=K;
            while(path!=N){
                path_print.push_back(path);
                path=path_memory[path];
            }
            path_print.push_back(N);
            return;
        }
        
        if(start-1>=0&&!visited[start-1]){
            path_memory[start-1]=start;
            visited[start-1]=1;
            q.push({start-1,time+1});
        }
        
        if(start+1<MAX&&!visited[start+1]){
            path_memory[start+1]=start;
            visited[start+1]=1;
            q.push({start+1,time+1});
        }
        
        if(start*2<MAX&&!visited[start*2]){
            path_memory[start*2]=start;
            visited[start*2]=1;
            q.push({start*2,time+1});
        }
        
        
        
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N>>K;
    
    bfs(N,0);
    cout<<sec<<'\n';
    for(int i=path_print.size()-1; i>=0; i--){
        cout<<path_print[i]<<' ';
    }
    if(path_print.empty()){
        cout<<N<<' '<<K;
    }
}
