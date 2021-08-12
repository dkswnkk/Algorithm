//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/16929
//  BOJ16929 Two Dots

#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

int N,M;

char map[51][51];
int visited[51][51];

int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

bool check;

void dfs(char color,int x,int y,int len,int originX,int originY){
    if(len>=4&&x==originX&&y==originY){
        check=true;
        return;
    }
    for(int i=0; i<4; i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0&&nx<N&&ny>=0&&ny<M){
            if(map[nx][ny]==color&&!visited[nx][ny]){
                visited[nx][ny]=1;
                dfs(color,nx,ny,len+1,originX,originY);
                visited[nx][ny]=0;
            }
        }
    }
    
    
    
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int k=0; k<M; k++){
            cin>>map[i][k];
        }
    }
    
    for(int i=0; i<N; i++){
        for(int k=0; k<M; k++){
            if(check){
                cout<<"Yes";
                return 0;
            }
            else{
                dfs(map[i][k],i,k,0,i,k);
                memset(visited, 0, sizeof(visited));
            }
        }
    }
    
    cout<<"No";
}
