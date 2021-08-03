//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/16948
//  BOJ16948 데스 나이트

#include <iostream>
#include <queue>

using namespace std;

int N;

int map[201][201];
int visited[201][201];

int dx[6]={-2,-2,0,0,2,2};
int dy[6]={-1,1,-2,2,-1,1};

int r1,c1,r2,c2;

void bfs(int x,int y){
    queue<pair<int,int>>q;
    visited[x][y]=1;
    q.push({x,y});
    
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0; i<6; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0&&nx<N&&ny>=0&&ny<N&&!visited[nx][ny]){
                q.push({nx,ny});
                visited[nx][ny]=1;
                map[nx][ny]=map[x][y]+1;
            }
        }
    }
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N;
    cin>>r1>>c1>>r2>>c2;
    
    
    bfs(r1,c1);
    if(map[r2][c2]==0) cout<<-1;
    else cout<<map[r2][c2];
}
