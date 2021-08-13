//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/1261
//  BOJ1261 알고스팟

#include <iostream>
#include <queue>
using namespace std;

/*
 N,M을 통상적인 위치로 x,y로 썼다가 반대라는 걸 예제를 돌리다가 알았다. 문제를 자세하게 보자.
 */
int N,M;
int map[101][101];
int visited[101][101];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};


int bfs(int x,int y){
    visited[y][x]=1;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    pq.push({0,{y,x}});
    
    while(!pq.empty()){
        
        int block=pq.top().first;
        int y=pq.top().second.first;
        int x=pq.top().second.second;
        
        if(x==M-1&&y==N-1){ //목적지인 (N,M)에 도달했을 때 즁료
            return block;
        }
        pq.pop();
        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0&&nx<M&&ny>=0&&ny<N&&!visited[ny][nx]){ //맵의 범위를 넘어가지 않고, 방문하지 않았을때
                visited[ny][nx]=1; //방문처리
                if(map[ny][nx]==0){
                    pq.push({block,{ny,nx}});   //벽안부수고 이동
                }
                else{
                    pq.push({block+1,{ny,nx}}); //벽 한개 부수고 이동
                }
                
            }
        }
    }
    return 0;
}
int main(){
    
    cin>>M>>N;
    for(int i=0; i<N; i++){
        for(int k=0; k<M; k++){
            scanf("%1d",&map[i][k]);
        }
    }
    
    cout<< bfs(0,0);
    
    
}
