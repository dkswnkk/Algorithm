#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

int N,M,T;
int map[101][101];

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
pair<int,int> knife_coor;
bool is_knife = false;
int knife_cost;
bool visited[101][101];

int not_use_knife(int x, int y){
    int temp[101][101] = {0, };
    queue<pair<int,int>> q;
    q.push({x,y});
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        visited[x][y] = 1;
        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0 && nx<N && ny>=0 && ny<M){
                if(!visited[nx][ny] && map[nx][ny]!= 1){
                    if(map[nx][ny] == 2) is_knife = true;
                    temp[nx][ny] = temp[x][y] + 1;
                    visited[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    knife_cost = temp[knife_coor.first][knife_coor.second];
    return temp[N-1][M-1];
}

int use_knife(int x, int y){
    int temp[101][101] = {0, };
    memset(visited, 0, sizeof(visited));
    queue<pair<int,int>> q;
    q.push({x,y});
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        visited[x][y] = 1;
        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0 && nx<N && ny>=0 && ny<M){
                if(!visited[nx][ny]){
                    temp[nx][ny] = temp[x][y] + 1;
                    visited[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    return temp[N-1][M-1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N>>M>>T;
    for(int i=0; i<N; i++){
        for(int k=0; k<M; k++){
            cin>>map[i][k];
            if(map[i][k] == 2) knife_coor = {i, k};
        }
    }
    int cost1 = not_use_knife(0, 0);
    int cost2 = 0;
    if(is_knife) cost2 = use_knife(knife_coor.first, knife_coor.second) + knife_cost;
    
    int fin_cost = 1e9;
    if(cost1 > 0 && cost2 > 0) fin_cost = min(cost1, cost2);
    else if(cost1 <= 0 && cost2 > 0) fin_cost = cost2;
    else if(cost1 > 0 && cost2 <= 0) fin_cost = cost1;
    
    if(fin_cost <= T) cout<< fin_cost;
    else cout<<"Fail";
}
