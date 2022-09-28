#include <iostream>
#include <memory.h>
using namespace std;

int N;
int map[11][11];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
bool visited[11][11];
int min_cost = 1e9;

void go(int x, int y, int depth, int cost){
    if(y >= N){
        y = 0;
        x += 1;
    }
    if(x>=N) return;
    if(depth == 3){
        min_cost = min(min_cost, cost);
        return;
    }
    bool visited_temp[11][11];
    memcpy(visited_temp, visited, sizeof(visited));
    if(!visited[x][y]){
        int cost_temp = map[x][y];
        int cnt = 0;
        for(int i=0; i<4; i++){ // 현재 칸에 꽃을 심는다.
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(!visited[nx][ny] && nx>=0 && nx<N && ny>=0 && ny<N){
                visited[nx][ny] = 1;
                cost_temp += map[nx][ny];
                cnt++;
            }
        }
        if(cnt == 4){
            go(x, y+1, depth + 1, cost + cost_temp);
        }
    }
    memcpy(visited, visited_temp, sizeof(visited));
    go(x, y+1, depth, cost);    // 현재칸에 꽃을 심지 않고 넘어간다.
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N;
    for(int i=0; i<N; i++){
        for(int k=0; k<N; k++){
            cin>>map[i][k];
        }
    }
    go(0,0,0,0);
    cout<<min_cost;
}
