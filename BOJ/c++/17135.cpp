#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;


int N, M, D, ans = -1, ans_temp;
int map_temp[16][16], map[16][16];


void attack_enemy(vector<pair<int,int>> enemy){
    for(auto it: enemy){
        if(it.first != 1e9 && it.second != 1e9){
            if(map_temp[it.first][it.second] == 1){
                map_temp[it.first][it.second] = 0;   // 적을 죽였으니 빈칸으로 만들어준다.
                ans_temp++; // 죽인 횟수 증가
            }
        }
    }
}


void move_enemy(){  // 적 이동
    vector<pair<int,int>> enemy_location;
    for(int i=0; i<N; i++){
        for(int k=0; k<M; k++){
            if(map_temp[i][k] == 1){
                int nr = i+1;
                int nc = k;
                if(nr<N) enemy_location.push_back({nr, nc});    // 아래로 이동했을 때 성이 있는 칸이 아니면 이동할 위치 기억
                map_temp[i][k] = 0;
            }
        }
    }
    
    for(auto it: enemy_location) map_temp[it.first][it.second] = 1; // 적 이동
}

bool isenemy(){ //적이 존재하는지 확인
    for(int i=0; i<N; i++){
        for(int k=0; k<M; k++){
            if(map_temp[i][k] == 1) return true;  // 적이 존재한다면
        }
    }
    return false;   // 적이 존재하지 않는다면
}

vector<pair<int,int>> find_enemy(int archer1, int archer2, int archer3){ // 적 위치 탐색
    int min_d1 = 1e9, min_d2 = 1e9, min_d3 = 1e9;
    int enemy_r1 = 1e9, enemy_c1 = 1e9, enemy_r2 = 1e9, enemy_c2 = 1e9, enemy_r3 = 1e9, enemy_c3 = 1e9;
    
    for(int i=0; i<N; i++){ // 각 궁수마다 가까운 적 탐색
        for(int k=0; k<M; k++){
            if(map_temp[i][k] == 1){ // 빈칸이 아니라 적일 경우
                int d1 = abs(N - i) + abs(archer1 - k);
                int d2 = abs(N - i) + abs(archer2 - k);
                int d3 = abs(N - i) + abs(archer3 - k);
                if(d1 <= min_d1 && d1 <= D){ // 궁수1이 죽일 적의 좌표
                    if(d1 == min_d1){
                        if(enemy_c1>k){
                            min_d1 = d1;
                            enemy_r1 = i;
                            enemy_c1 = k;
                        }
                    }
                    else{
                        min_d1 = d1;
                        enemy_r1 = i;
                        enemy_c1 = k;
                    }
                }
                if(d2 <= min_d2 && d2 <= D){ // 궁수2가 죽일 적의 좌표
                    if(d2 == min_d2){
                        if(enemy_c2>k){
                            min_d2 = d2;
                            enemy_r2 = i;
                            enemy_c2 = k;
                        }
                    }
                    else{
                        min_d2 = d2;
                        enemy_r2 = i;
                        enemy_c2 = k;
                    }
                    
                }
                if(d3 <= min_d3 && d3 <= D){ // 궁수3이 죽일 적의 좌표
                    if(d3 == min_d3){
                        if(enemy_c3>k){
                            min_d3 = d3;
                            enemy_r3 = i;
                            enemy_c3 = k;
                        }
                    }
                    else{
                        min_d3 = d3;
                        enemy_r3 = i;
                        enemy_c3 = k;
                    }
                    
                }
            }
        }
    }
    return {{enemy_r1, enemy_c1}, {enemy_r2, enemy_c2}, {enemy_r3, enemy_c3}};  // 각각 궁수가 쏴야할 적 좌표
}


void simulation(int archer1, int archer2, int archer3){
    memcpy(map_temp, map, sizeof(map));
    while(isenemy()){
        attack_enemy(find_enemy(archer1, archer2, archer3));
        move_enemy();
    }
    ans = max(ans, ans_temp);
    ans_temp = 0;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N>>M>>D;
    
    // 맵 입력
    for(int i=0; i<N; i++){
        for(int k=0; k<M; k++){
            cin>>map[i][k];
        }
    }
    
    // 궁수 세명 위치 고르기
    for(int a = 0; a < M; a++){
        for(int b = a+1; b < M; b++){
            for(int c = b+1; c < M; c++){
                simulation(a, b, c);
            }
        }
    }
    
    cout<<ans;
    
}
