#include <iostream>
#include <queue>
using namespace std;

int N,M;

int map[101][101];
int visited[101][101];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

int right_on = 0,right_off=0;

void go_rignt_on(int x, int y){
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
            
            if(nx>=0&&nx<N&&ny>=0&&ny<M){
                if(visited[nx][ny]||map[nx][ny]==1) continue;
                q.push({nx,ny});
                visited[nx][ny]=1;
            }
        }
    }
    right_on++;
}

void go_rignt_off(int x, int y){
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
            
            if(nx>=0&&nx<N&&ny>=0&&ny<M){
                if(visited[nx][ny]||map[nx][ny]==0) continue;
                q.push({nx,ny});
                visited[nx][ny]=1;
            }
        }
    }
    right_off++;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    
    cin>>N>>M;
    
    for(int i=0; i<N; i++){
        for(int k=0; k<M; k++){
            cin>>map[i][k];
        }
    }
    
    for(int i=0; i<N; i++){
        for(int k=0; k<M; k++){
            if(map[i][k]==0&&!visited[i][k]) go_rignt_on(i,k);
        }
    }
    memset(visited,0,sizeof(0));
    for(int i=0; i<N; i++){
        for(int k=0; k<M; k++){
            if(map[i][k]==1&&!visited[i][k]) go_rignt_off(i,k);
        }
    }
    cout<<right_on<<' '<<right_off;
    
}
