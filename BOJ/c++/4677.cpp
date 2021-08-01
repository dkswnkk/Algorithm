//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/4677
//  BOJ4677 Oil Deposits

#include <iostream>
#include <queue>

using namespace std;

int m,n;
int map[101][101];
int visited[101][101];

int dx[8]={0,0,-1,1,-1,-1,1,1}; // 상 하 좌 우 대각선
int dy[8]={-1,1,0,0,-1,1,-1,1};

int ans;


void init(){
    for(int i=0; i<101; i++){
        for(int k=0; k<101; k++){
            map[i][k]=0;
            visited[i][k]=0;
        }
    }
    ans=0;
}

void bfs(int x,int y){
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
            
            if(nx>=0&&nx<m&&ny>=0&&ny<n){
                if(map[nx][ny]=='@'&&!visited[nx][ny]){
                    visited[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }
    }
    ans++;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    while(cin>>m>>n){
        if(m==0&&n==0) break; //입력이 0 0 이면 종료.
        
        for(int i=0; i<m; i++){
            string inp; cin>>inp;
            for(int k=0; k<n; k++){
                map[i][k]=inp[k];
            }
        }
        for(int i=0; i<m; i++){
            for(int k=0; k<n; k++){
                if(map[i][k]=='@'&&!visited[i][k]) bfs(i,k);
            }
        }
        cout<<ans<<'\n';
        init();
    }
}
