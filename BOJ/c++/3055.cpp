//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/3055
//  BOJ3055 탈출

#include <iostream>
#include <queue>

using namespace std;

int R,C;
char map[51][51];
int visited[51][51];
const int dx[4]={0,0,-1,1};
const int dy[4]={-1,1,0,0};
queue<pair<int,int>>q_water;
queue<pair<int,pair<int,int>>>q_dochi;

void water(){
    int water_size = q_water.size();
    while(water_size--){
        int x=q_water.front().first;
        int y=q_water.front().second;
        q_water.pop();
        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0&&nx<R&&ny>=0&&ny<C){ //맵 범위를 넘어가지않고, 방문하지 않았을 때
                if (map[nx][ny]=='.'){
                q_water.push({nx,ny});
                map[nx][ny]='*';
                }
            }
        }
    }
}

int dochi(){
    while(!q_dochi.empty()){
        water();
        int start_size = q_dochi.size();
        while (start_size--) {
            int time=q_dochi.front().first;
            int x=q_dochi.front().second.first;
            int y=q_dochi.front().second.second;
            q_dochi.pop();
            visited[x][y]=1;
            
            if(map[x][y]=='D') return time;
            
            for(int i=0; i<4; i++){
                map[x][y]='.';
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0&&nx<R&&ny>=0&&ny<C&&!visited[nx][ny]){ //맵 범위를 넘어가지않고, 방문하지 않았을 때
                    if(map[nx][ny]=='.'||map[nx][ny]=='D'){   //빈칸일때
                        visited[nx][ny]=1;
                        q_dochi.push({time+1,{nx,ny}});
                    }
                }
            }
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>R>>C;
    for(int i=0; i<R; i++){
        for(int k=0; k<C; k++){
            cin>>map[i][k];
            if(map[i][k]=='S'){
                q_dochi.push({0,{i,k}});
            }
            else if(map[i][k]=='*'){
                q_water.push({i,k});
            }
        }
        
    }
    int ans=dochi();
    if(ans==0) cout<<"KAKTUS";
    else cout<<ans;
    
    
}

