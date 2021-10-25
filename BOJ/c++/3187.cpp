//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnzz
//  https://www.acmicpc.net/problem/3187
//  BOJ3187 양치기 꿍

#include <iostream>
#include <queue>

using namespace std;

char map[251][251];
int R,C,w,s;
int visited[251][251];
const int dx[4]={0,0,-1,1};
const int dy[4]={-1,1,0,0};



void bfs(int x,int y){
    queue<pair<int,int>>q;
    q.push({x,y});
    visited[x][y]=1;
    
    int wolf_cnt=0,sheep_cnt=0;
    
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        if(map[x][y]=='v') wolf_cnt++;
        if(map[x][y]=='k') sheep_cnt++;
        
        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            
            if(nx>=0&&nx<R&&ny>=0&&ny<C){
                if(!visited[nx][ny]&&map[nx][ny]!='#'){
                    visited[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }
    }
    
    if(!sheep_cnt&&!wolf_cnt) return;
    
    if(sheep_cnt>wolf_cnt) s+=sheep_cnt;
    else w+=wolf_cnt;
}
int main(){
    
    scanf("%d %d",&R,&C);
    getchar();
    
    for(int i=0; i<R; i++){ //inp
        for(int k=0; k<C; k++){
            scanf("%c",&map[i][k]);
        }
        getchar();
    }
    
    for(int i=0; i<R; i++){
        for(int k=0; k<C; k++){
            if(!visited[i][k]&&map[i][k]!='#') bfs(i,k);
        }
    }
    cout<<s<<' '<<w;
}
