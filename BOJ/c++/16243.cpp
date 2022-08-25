#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

int N,L,R, day;
int map[51][51];
int line[51][51];
bool visited[51][51];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool line_check(){
    bool flag = false;
    for(int i=0; i<N; i++){ // 가로 확인
        for(int k=0; k<N-1; k++){
            int diff = abs(map[i][k] - map[i][k+1]);
            if(diff>=L && diff<=R){ // 인구 차이가 L명이상, R명 이하일 때
                flag = true;
                line[i][k] = 1;
                line[i][k+1] = 1;
            }
        }
    }
    
    for(int k=0; k<N; k++){ // 세로 확인
        for(int i=0; i<N-1; i++){
            int diff = abs(map[i][k] - map[i+1][k]);
            if(diff>=L && diff<=R){ // 인구 차이가 L명이상, R명 이하일 때
                flag = true;
                line[i][k] = 1;
                line[i+1][k] = 1;
            }
        }
    }
    
    return flag;
}


void search_union(int x, int y){ // 연합 탐색
    int peo_sum = map[x][y];
    int blank_cnt = 1;
    visited[x][y] = 1;
    queue<pair<int,int>> q;
    vector<pair<int,int>> coor = {{x, y}};
    q.push({x,y});
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0 && nx<N && ny>=0 && ny<N){
                int diff = abs(map[x][y] - map[nx][ny]);
                if(!visited[nx][ny] && diff>=L && diff<=R){
                    visited[nx][ny] = 1;
                    q.push({nx, ny});
                    blank_cnt++;
                    peo_sum += map[nx][ny];
                    coor.push_back({nx, ny});
                }
            }
        }
    }
    
    int population = peo_sum / blank_cnt;   // 각 칸을 이룰 새로운 인구 수
    for(auto it: coor) map[it.first][it.second] = population;   //인구 이동
    
}

void move(){
    for(int i=0; i<N; i++){
        for(int k=0; k<N; k++){
            if(line[i][k] && !visited[i][k]) search_union(i, k);
        }
    }
}


void simulation(){
    
    while(line_check()){
        day++;
        move();
        memset(visited, 0 ,sizeof(visited));
        memset(line, 0, sizeof(line));
    }
    
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N>>L>>R;
    
    for(int i=0; i<N; i++){
        for(int k=0; k<N; k++){
            cin>>map[i][k];
        }
    }
    simulation();
    cout<<day;
}
