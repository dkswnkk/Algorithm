//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/1987
//  BOJ1987 알파벳

#include <iostream>
#include <map>
using namespace std;


int R,C;
char graph[21][21];
int ans=-9999;
map<char,int>m;

int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

void dfs(int x,int y,int len){
    m[graph[x][y]]=1;
    for(int i=0; i<4; i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0&&nx<R&&ny>=0&&ny<C){
            if(m[graph[nx][ny]]==0){  //방문했던 알파벳이 아닐때만 탐색
                m[graph[nx][ny]]=1;
                dfs(nx,ny,len+1);
                m[graph[nx][ny]]=0;
            }
        }
    }
    
    ans=max(ans,len);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ㅌ
    cin>>R>>C;
    
    for(int i=0; i<R; i++){
        for(int k=0; k<C; k++){
            cin>>graph[i][k];
        }
    }
    dfs(0,0,1);
    cout<<ans;
}
