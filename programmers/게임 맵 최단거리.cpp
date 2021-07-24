#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int map[101][101];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int n1,n2;


void bfs(int x,int y){
    queue<pair<int,int>>q;
    q.push({x,y});
    
    while (!q.empty()) {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){ //상 하 좌 우 탐색
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(map[nx][ny]==1&&nx>=0&&nx<n1&&ny>=0&&ny<n2){
                map[nx][ny]=map[x][y]+1;
                q.push({nx,ny});
            }
            
        }
    }
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    for(int i=0; i<maps.size(); i++){
        for(int k=0; k<maps[i].size(); k++){
            map[i][k]=maps[i][k];
        }
    }
    
    n1=maps.size();
    n2=maps[0].size();
    
    bfs(0,0);
    
    answer=map[n1-1][n2-1];
    
    if(map[n1-1][n2-1]!=1&&map[n1-1][n2-1]!=0) answer=map[n1-1][n2-1];
    else answer=-1;
    
    return answer;
}
