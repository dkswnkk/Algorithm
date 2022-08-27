#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

int N, _time;
int map[21][21], cost[21][21];
int shark_r, shark_c, shark_size, now_eat_cnt;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
bool visited[21][21];

pair<int,int> find_near_fish_coor(){ // 현재 상어위치에서 가장 가까운 물고기의 좌표를 찾음
    int min_dist = 1e9;
    int fish_r = 1e9, fish_c = 1e9;
    for(int i=0; i<N; i++){
        for(int k=0; k<N; k++){
            if(map[i][k] !=9 && map[i][k]!=0 && map[i][k]<shark_size && cost[i][k] != 0){
                int dist = cost[i][k];
                if(dist == min_dist){   // 물고기의 거리가 같을 때
                    if(i == fish_r){    // 물고기의 높이가 같을 때
                        if(k <= fish_c){    // 가장 왼쪽에 있는 물고기를 고름
                            fish_r = i;
                            fish_c = k;
                            min_dist = dist;
                        }
                    }
                    else if(i<fish_r){
                        fish_r = i;
                        fish_c = k;
                        min_dist = dist;
                    }
                }
                else if(dist<min_dist){
                    fish_r = i;
                    fish_c = k;
                    min_dist = dist;
                }
            }
        }
    }
    return {fish_r, fish_c};
}

void cal_dist(int r, int c){
    visited[r][c] = 1;
    queue<pair<int,int>> q;
    q.push({r,c});
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 && nx<N && ny>=0 && ny<N){
                if(!visited[nx][ny] && shark_size>=map[nx][ny]){ // 아기 상어는 자신과 크기가 같거나 작은 물고기만 지나갈 수 있음
                    visited[nx][ny] = 1;
                    cost[nx][ny] = cost[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
}

bool move_and_eat_fish(pair<int,int> fish_coor){
    int x = fish_coor.first;
    int y = fish_coor.second;
    if(x == 1e9 || y == 1e9) return false;  // 상어보다 덩치가 작은 물고기가 있지만 덩치가 큰 물고기들 때문에 먹으러 가지 못할 경우
    _time += cost[x][y];
    map[shark_r][shark_c] = 0;
    shark_r = x;
    shark_c = y;
    map[shark_r][shark_c] = 9;
    now_eat_cnt++;
    if(now_eat_cnt == shark_size){
        shark_size++;
        now_eat_cnt = 0;
    }
    return true;
}

bool isfish(){  // 먹을 수 있는물고기가 남아있는지 확인
    for(int i=0; i<N; i++){
        for(int k=0; k<N; k++){
            if(map[i][k] == 9) continue;
            if(map[i][k]!=0 && map[i][k] < shark_size) return true;
        }
    }
    return false;
}

void simulation(){
    while(isfish()){
        cal_dist(shark_r, shark_c);
        if(!move_and_eat_fish(find_near_fish_coor())) return;
        memset(visited, 0 ,sizeof(visited));
        memset(cost, 0, sizeof(cost));
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N;
    
    for(int i=0; i<N; i++){
        for(int k=0; k<N; k++){
            cin>>map[i][k];
            if(map[i][k] == 9){
                shark_r = i;
                shark_c = k;
                shark_size = 2;
            }
        }
    }
    simulation();
    cout<<_time;
}
