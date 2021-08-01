//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/14716
//  BOJ14716 현수막

#include <iostream>
#include <queue>

using namespace std;


int M,N;
int map[251][251];
int visited[251][251];
int dx[8]={0,0,-1,1,-1,-1,1,1}; //상 하 좌 우 대각선
int dy[8]={-1,1,0,0,-1,1,-1,1};

int ans=0;

void bfs(int x,int y){
    ans++;
    queue<pair<int,int>>q;
    q.push({x,y});
    visited[x][y]=1;
    
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        
        for(int i=0; i<8; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0&&nx<M&&ny>=0&&ny<N){   //범위를 넘지 않을때
                if(map[nx][ny]==1&&!visited[nx][ny]){
                    visited[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>M>>N;
    
    for(int i=0; i<M; i++){
        for(int k=0; k<N; k++){
            cin>>map[i][k];
        }
    }
    for(int i=0; i<M; i++){
        for(int k=0; k<N; k++){
            if(map[i][k]==1&&!visited[i][k]) bfs(i,k);
        }
    }
    
    cout<<ans;
}
