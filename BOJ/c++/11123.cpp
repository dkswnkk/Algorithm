//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/11123
//  BOJ11123 양 한마리... 양 두마리...

#include <iostream>
#include <queue>

using namespace std;


int H,W;
char map[101][101];
int visited[101][101];

int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
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
        
        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0&&nx<H&&ny>=0&&ny<W){
                if(!visited[nx][ny]&&map[nx][ny]=='#'){
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
    
    int T; cin>>T;
    
    while(T--){
        
        cin>>H>>W;
        
        
        for(int i=0; i<H; i++){
            string inp; cin>>inp;
            for(int k=0; k<W; k++){
                map[i][k]=inp[k];
            }
        }
        
        for(int i=0; i<H; i++){
            for(int k=0; k<W; k++){
                if(map[i][k]=='#'&&!visited[i][k]) bfs(i,k);
            }
        }
        
        cout<<ans<<'\n';
        init();
    }
    
}
