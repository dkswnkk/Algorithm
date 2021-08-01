//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/15240
//  BOJ15240 Paint bucket

#include <iostream>
#include <queue>

using namespace std;

int map[1001][1001];
int visited[1001][1001];
int ans;
int Y,X,K;
int R,C;
int original;   //원래 값
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

void bfs(int x,int y){
    queue<pair<int,int>>q;
    q.push({x,y});
    visited[x][y]=1;
    
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0&&nx<R&&ny>=0&&ny<C){
                if(map[nx][ny]==original&&!visited[nx][ny]){
                    visited[nx][ny]=1;
                    map[nx][ny]=K;
                    q.push({nx,ny});
                    
                }
            }
        }
    }
}
int main(){
    
    cin>>R>>C;
    
    for(int i=0; i<R; i++){
        for(int k=0; k<C; k++){
            scanf("%1d",&map[i][k]);
        }
    }
    
    cin>>Y>>X>>K;
    
    original=map[Y][X];
    
    bfs(Y,X);
    
    map[Y][X]=K;    //시작점 바꿔준다.
    
    for(int i=0; i<R; i++){
        for(int k=0; k<C; k++){
            cout<<map[i][k];
        }
        cout<<'\n';
    }
}
