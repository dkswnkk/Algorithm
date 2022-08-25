#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>
#define INF 1e9
using namespace std;


int N, M;
int map[51][51];
vector<pair<int,int>> store;    // 치킨집 좌표
bool is_store[51][51];  // 폐업하지 않은 치킨집인지 유무
int house_store_dist[51][51];  // 해당 집에서 가장 가까운 치킨집과의 거리
int ans = INF;

void dist(){    // 집과 치킨집 사이의 거리 갱신
    for(int i=0; i<N; i++){
        for(int k=0; k<N; k++){
            if(map[i][k] == 1){    // 집일때
                for(auto it : store){
                    if(is_store[it.first][it.second] == 1){ // 폐업하지 않은 치킨 집일 때
                        int dist = abs(it.first - i) + abs(it.second - k);
                        house_store_dist[i][k] = min(house_store_dist[i][k], dist); // 최소 거리 갱신
                    }
                }
            }
        }
    }
}

void check_min_dist(){
    int ans_temp = 0;
    for(int i=0; i<N; i++){
        for(int k=0; k<N; k++){
            if(map[i][k] == 1) ans_temp += house_store_dist[i][k];
        }
    }
    ans = min(ans_temp, ans);
}


void backtraking(int idx, int is_store_cnt){
    if(is_store_cnt>M) return;    // 촤대 폐업 가능 수 보다 더 많이 폐업했을 때 return
    if(is_store_cnt>0){
        dist();
        check_min_dist();
    }
    
    for(int i = idx; i<store.size(); i++){
        int r = store[i].first;
        int c = store[i].second;
        
        is_store[r][c] = 1; // 폐업하지 않은 치킨집
        int backup[51][51] = {};
        memcpy(backup, house_store_dist, sizeof(house_store_dist));
        backtraking(i+1, is_store_cnt+1);
        memcpy(house_store_dist, backup, sizeof(backup));
        is_store[r][c] = 0; // 폐업한 치킨집
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>M;
    
    for(int i=0; i<N; i++){
        for(int k=0; k<N; k++){
            cin>>map[i][k];
            if(map[i][k] == 2) store.push_back({i, k});
        }
    }
    for(int i=0; i<51; i++) fill(house_store_dist[i], house_store_dist[i]+51, INF);
    backtraking(0, 0);
    cout<<ans;
}
