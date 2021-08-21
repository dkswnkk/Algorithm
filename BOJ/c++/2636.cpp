//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/2636
//  BOJ2636 치즈

#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

int map[101][101];
int visited[101][101];
int cheese_memory;
int R,C,cnt,cheese_cnt;
queue<pair<int,int>> q;

const int dx[4]={0,0,-1,1};
const int dy[4]={-1,1,0,0};


bool no_cheese(){
    for(int i=0; i<R; i++){
        for(int k=0; k<C; k++){
            if(map[i][k]==1){
                return false;
            }
        }
    }
    return true;
}

int count_cheese(){
    int temp=0;
    for(int i=0; i<R; i++){
        for(int k=0; k<C; k++){
            if(map[i][k]==1){
                temp++;
            }
        }
    }
    return temp;
}

void bfs(int x,int y){
    q.push({x,y});
    visited[x][y]=1;
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        visited[x][y]=1;
        q.pop();
        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0&&nx<R&&ny>=0&&ny<C&&!visited[nx][ny]){
                if(map[nx][ny]==1){ //공기가 치즈에 닿으면
                    map[nx][ny]=0;  //공기로 변경
                }
                else q.push({nx,ny});
                visited[nx][ny]=1;
            }
        }
    }
    
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>R>>C;
    for(int i=0; i<R; i++){
        for(int k=0; k<C; k++){
            cin>>map[i][k];
        }
    }
    
    while(1){
        cheese_memory=count_cheese();
        bfs(0,0);
        memset(visited, 0, sizeof(visited));
        cnt++;
        if(no_cheese())break;       //남은 치즈가 더 이상 없을 경우 종료
    }
    
    cout<<cnt<<'\n'<<cheese_memory;
}
