//  Copyright © 2021 안주형. All rights reserved.
//  https://github.com/dkswnkk
//  https://www.acmicpc.net/problem/14923
//  BOJ14923 미로 탈출

#include <iostream>
#include <queue>
using namespace std;

int N,M,start_x,start_y,arrived_x,arrived_y,ans;
int map[1001][1001];
int visited[1001][1001][2];
const int dx[4]={0,0,-1,1};
const int dy[4]={-1,1,0,0};

int bfs(int x,int y){
    queue<pair<int,pair<int,int>>>q;    //{벽 뚫기 여부,{x,y}}
    q.push({1,{x,y}});  //벽을 뚫을 수 있으면 1
    visited[x][y][1]=1;
    
    while(!q.empty()){
        int wand=q.front().first;
        int x=q.front().second.first;
        int y=q.front().second.second;
        if(x==arrived_x-1&&y==arrived_y-1){ //도착했을 때 종료
            return visited[x][y][wand];
        }
        q.pop();
        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0&&nx<N&&ny>=0&&ny<M){   //벽의 범위를 벗어나지 않았을 때
                if(map[nx][ny]==1&&wand){   //벽이 있고, 지팡이를 사용 할 수 있을 때
                    visited[nx][ny][wand-1] = visited[x][y][wand]+1;    //벽을 뚫고 이전 최단거리에 +1 해준다.
                    q.push({wand-1,{nx,ny}});
                }
                else if(map[nx][ny]==0&&!visited[nx][ny][wand]){    //벽이 없고, 방문하지 않았던 곳일경우
                    visited[nx][ny][wand]=visited[x][y][wand]+1;
                    q.push({wand,{nx,ny}});
                    
                }
                
            }
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N>>M>>start_x>>start_y>>arrived_x>>arrived_y;
    
    for(int i=0; i<N; i++){
        for(int k=0; k<M; k++){
            cin>>map[i][k];
        }
    }
    
    ans=bfs(start_x-1,start_y-1);
    if(ans==-1) cout<<-1;
    else cout<<ans-1;
    
}
