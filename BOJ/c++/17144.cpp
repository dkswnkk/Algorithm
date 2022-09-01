#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

int R, C, T;
int map[51][51];
vector<pair<int,int>> air_cleaner;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

struct SpreadInfo{
    int amount; // 확산된 미세먼지 양
    int r;
    int c;
};

struct LeftInfo{
    int amount; // 남은 미세먼지 양
    int r;
    int c;
};

vector<pair<int,int>> find_dust(){
    vector<pair<int,int>> v;
    for(int i=0; i<R; i++){
        for(int k=0; k<C; k++){
            if(map[i][k] != -1 && map[i][k] != 0) v.push_back({i , k});
        }
    }
    return v;
}

void spread(){
    vector<pair<int,int>> dust = find_dust();
    vector<SpreadInfo> spreadInfo;
    vector<LeftInfo> leftInfo;
    
    for(auto next: dust){
        int r = next.first;
        int c = next.second;
        int spread_cnt = 0;
        for(int i=0; i<4; i++){
            int nx = r + dx[i];
            int ny = c + dy[i];
            if(nx>=0 && nx < R && ny>=0 && ny<C){   // 맵 범위안에 있고
                if(map[nx][ny] != -1){ // 공기청정기가 아닐 때
                    spreadInfo.push_back({map[r][c] / 5, nx, ny}); // 확산되는 양은 Ar,c/5이고 소수점은 버린다.
                    spread_cnt++;
                }
            }
        }
        leftInfo.push_back({map[r][c] - ((map[r][c] / 5) * spread_cnt), r, c}); // (r, c)에 남은 미세먼지의 양은 Ar,c - (Ar,c/5)×(확산된 방향의 개수) 이다.
        spread_cnt = 0;
    }
    memset(map, 0, sizeof(map));
    for(auto it : leftInfo) map[it.r][it.c] = it.amount;
    for(auto it : spreadInfo) map[it.r][it.c] += it.amount;
    
    map[air_cleaner[0].first][air_cleaner[0].second] = -1;
    map[air_cleaner[1].first][air_cleaner[1].second] = -1;
    
}


void air_cleaner_upper(){ // 공기청정기 위 반시계방향 순환
    int upper_air_cleaner_r = air_cleaner[0].first;
    int upper_air_cleaner_c = air_cleaner[0].second;
    
    int x1 = 0, y1 = 0; // 좌측 상단
    int x2 = 0, y2 = C-1;   // 우측 상단
    int x3 = upper_air_cleaner_r, y3 = C-1;   // 우측 하단
    int x4 = upper_air_cleaner_r, y4 = 0; // 좌측 하단
    
    int temp = map[x1][y1];
    
    for(int i = y1; i < y2; i++){   // 1
        if(map[x1][i] == -1) continue;
        map[x1][i+1] == -1 ? map[x1][i] = 0 : map[x1][i] = map[x1][i+1];
    }
    for(int i = x2; i < x3; i++){   // 2
        if(map[i][y2] == -1) continue;
        map[i+1][y2] == -1 ? map[i][y2] = 0 : map[i][y2] = map[i+1][y2];
    }
    for(int i = y3; i > y4; i--){   // 3
        if(map[x3][i] == -1) continue;
        map[x3][i-1] == -1 ? map[x3][i] = 0 : map[x3][i] = map[x3][i-1];
    }
    for(int i = x4; i > x1; i--){    // 4
        if(map[i][y4] == -1) continue;
        map[i-1][y4] == -1 ? map[i][y4] = 0 : map[i][y4] = map[i-1][y4];
    }
    
    temp == -1 ? map[x1+1][y4] = 0 : map[x1+1][y4] = temp;
    map[upper_air_cleaner_r][upper_air_cleaner_c] = -1;
}


void air_cleaner_lower(){ // 공기청정기 아래 시계방향 순환
    int lower_air_cleaner_r = air_cleaner[1].first;

    int x1 = lower_air_cleaner_r, y1 = 0; // 좌측 상단
    int x2 = lower_air_cleaner_r, y2 = C-1;   // 우측 상단
    int x3 = R-1, y3 = C-1;   // 우측 하단
    int x4 = R-1, y4 = 0; // 좌측 하단
    
    int temp = map[x1][y1];
    
    for(int i = x1; i < x4; i++){   // 4
        if(map[i][y1] == -1) continue;
        map[i+1][y1] == -1 ? map[i][y1] = 0 : map[i][y1] = map[i+1][y1];
    }
    for(int i = y4; i < y3; i++){   // 3
        if(map[x3][i] == -1) continue;
        map[x3][i+1] == -1 ? map[x3][i] = 0 : map[x3][i] = map[x3][i+1];
    }
    for(int i = x3; i > x2; i--){   // 2
        if(map[i][y2] == -1) continue;
        map[i-1][y2] == -1 ? map[i][y2] = 0 : map[i][y2] = map[i-1][y2];
    }
    
    for(int i = y2; i > y1; i--){   // 1
        if(map[x1][i] == -1) continue;
        map[x1][i-1] == -1 ? map[x1][i] = 0 : map[x1][i] = map[x1][i-1];
    }
    temp == -1 ? map[x1][y1+1] = 0 : map[x1][y1+1] = temp;
}

void clean_dust(){
    air_cleaner_upper();
    air_cleaner_lower();
}

void simulation(){
    find_dust();
    spread();
    clean_dust();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>R>>C>>T;
    
    for(int i=0; i<R; i++){
        for(int k=0; k<C; k++){
            cin>>map[i][k];
            if(map[i][k] == -1) air_cleaner.push_back({i ,k});
        }
    }
    
    while(T--){
        simulation();
    }
    int ans = 0;
    for(int i=0; i<R; i++){
        for(int k=0; k<C; k++){
            if(map[i][k] != -1) ans += map[i][k];
        }
    }
    cout<<ans;
}
