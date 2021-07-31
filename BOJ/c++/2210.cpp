//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/2210
//  BOJ2210 숫자판 점프

#include <iostream>
#include <map>

using namespace std;

int maps[5][5];

int dx[4]={0,0,-1,1};
int dy[5]={-1,1,0,0};
int ans=0;
map<string,int>m;

void dfs(int x,int y,string cnt){
    if(cnt.length()==6){
        if(m[cnt]==0){
            m[cnt]=1;
            ans++;
        }
        return;
    }
    for(int i=0; i<4; i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0&&nx<5&&ny>=0&&ny<5){
            cnt+=to_string(maps[nx][ny]);
            dfs(nx,ny,cnt);
            cnt.pop_back();
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    for(int i=0; i<5; i++){
        for(int k=0; k<5; k++){
            cin>>maps[i][k];
        }
    }
    
    for(int i=0; i<5; i++){
        for(int k=0; k<5; k++){
            dfs(i,k,to_string(maps[i][k]));
        }
    }
    
    cout<<ans;
}
