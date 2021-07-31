//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/3184
//  BOJ3184 양

#include <iostream>
#include <queue>

using namespace std;

int R,C;
char map[251][251];
int visited[251][251];

int dx[4]={0,0,-1,1};   //상 하 좌 우
int dy[4]={-1,1,0,0};

int o,v;

void bfs(int x,int y){
    visited[x][y]=1;
    
    int sheep=0,wolf=0;
    queue<pair<int,int>>q;
    q.push({x,y});
    
    while(!q.empty()){
        
        int x=q.front().first;
        int y=q.front().second;
        
        if(map[x][y]=='o') sheep++;
        if(map[x][y]=='v') wolf++;
        
        q.pop();
        
        for(int i=0; i<4; i++){ //상 하 좌 우 탐색
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<R&&nx>=0&&ny>=0&&ny<C){   //영역을 벗어나지 않을 때
                if(map[nx][ny]!='#'&&!visited[nx][ny]){   //울타리가 아니고 방문하지 않았을 때
                    visited[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }
    }
    if(sheep>wolf) o+=sheep;
    else v+=wolf;
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
    
    for(int i=0; i<R; i++){
        for(int k=0; k<C; k++){
           if(!visited[i][k]&&map[i][k]!='#') bfs(i,k);
        }
    }
    cout<<o<<' '<<v;
    
}
