#include <iostream>
#include <vector>

using namespace std;

int N, ans;
int map[21][21];
int favorite[442][5];
int dr[4] = {0,0,-1,1};
int dc[4] = {-1,1,0,0};
int peo[442][4];

vector<pair<int,int>> find_blank(){ // 현재 비어있는 좌표찾기
    vector<pair<int,int>> v; // 비어있는 칸의 좌표를 담을 벡터
    for(int i=0; i<N; i++){
        for(int k=0; k<N; k++){
            if(map[i][k] == 0) v.push_back({i, k});
        }
    }
    return v;
}

vector<pair<int,int>> find_near_blank(vector<pair<int,int>> v){
    vector<pair<int,int>> coor;
    vector<pair<int,pair<int,int>>> blank_cnt_check;
    int max_black_cnt = 0;
    for(auto it : v){
        int r = it.first;
        int c = it.second;
        int blank_cnt_temp = 0;
        for(int i=0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr >= 0 && nr < N && nc >= 0 && nc < N){
                for(int k = 1; k < 5; k++){
                    if(map[nr][nc] == 0) blank_cnt_temp++;
                }
            }
        }
        if(blank_cnt_temp >= max_black_cnt){
            max_black_cnt = blank_cnt_temp;
            blank_cnt_check.push_back({max_black_cnt,{r,c}});
        }
    }
    for(auto it: blank_cnt_check){
        if(it.first == max_black_cnt) coor.push_back({it.second.first, it.second.second});
    }
    return coor;
}

vector<pair<int,int>> find_near_favorite(int idx, vector<pair<int,int>> blank_coor){  // 좋아하는 학생이 가장 많은 인정한 칸 좌표 찾기
    vector<pair<int,int>> coor;
    vector<pair<int,pair<int,int>>> favorite_cnt_check;
    int max_favorite_cnt = 0;
    for(auto it: blank_coor){
        int r = it.first;
        int c = it.second;
        int favorite_cnt_temp = 0;
        for(int i=0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr >= 0 && nr < N && nc >= 0 && nc < N){
                for(int k = 1; k < 5; k++){
                    if(favorite[idx][k] == map[nr][nc]) favorite_cnt_temp++;
                }
            }
        }
        if(favorite_cnt_temp >= max_favorite_cnt){
            max_favorite_cnt = favorite_cnt_temp;
            favorite_cnt_check.push_back({max_favorite_cnt, {r, c}});
        }
    }
    for(auto it: favorite_cnt_check){
        if(it.first == max_favorite_cnt) coor.push_back({it.second.first, it.second.second});
    }
    return coor;
}

vector<pair<int,int>> find_min_r(vector<pair<int,int>> coor){
    int min_r = 1e9;
    vector<pair<int,int>> v;
    for(auto it : coor) min_r = min(min_r, it.first);
    for(auto it : coor){
        if(it.first == min_r) v.push_back({it.first, it.second});
    }
    return v;
}

vector<pair<int,int>> find_min_c(vector<pair<int,int>> coor){
    int min_c = 1e9;
    vector<pair<int,int>> v;
    for(auto it : coor) min_c = min(min_c, it.second);
    for(auto it : coor){
        if(it.second == min_c) v.push_back({it.first, it.second});
    }
    return v;
}


void survey(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int score = 0;
            for(int k=0; k<4; k++){
                int nr = i + dr[k];
                int nc = j + dc[k];
                if(nr >= 0 && nr < N && nc >= 0 && nc < N){
                    for(int z = 0; z<4; z++){
                        if(peo[map[i][j]][z] == map[nr][nc]) score++;
                    }
                }
            }
            if(score == 1) ans += 1;
            else if(score == 2) ans += 10;
            else if(score == 3) ans += 100;
            else if(score == 4) ans += 1000;
        }
    }
}

void simulation(){
    for(int i=0; i<N*N; i++){
        vector<pair<int,int>> coor = find_near_favorite(i, find_blank()); // 비어있는 칸 중에서 좋아하는 학생이 인접한 칸에 가장 많은 칸으로 자리를 정한다.
        if(coor.size() > 1){ // 1을 만족하는 칸이 여러 개이면, 인접한 칸 중에서 비어있는 칸이 가장 많은 칸으로 자리를 정한다.
            coor = find_near_blank(coor);
            if(coor.size() > 1){ // 2를 만족하는 칸도 여러 개인 경우에는 행의 번호가 가장 작은 칸으로 정한다.
                coor = find_min_r(coor);
                if(coor.size() > 1){ //  그러한 칸도 여러 개이면 열의 번호가 가장 작은 칸으로 자리를 정한다.
                    coor = find_min_c(coor);
                }
            }
        }
        map[coor.front().first][coor.front().second] = favorite[i][0];
    }
    survey();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N;
    for(int i=0; i<N * N; i++){
        int _peo = 0;
        for(int k=0; k<5; k++){
            int inp; cin>>inp;
            if(k == 0) _peo = inp;
            if(k != 0) peo[_peo][k-1] = inp;
            favorite[i][k] = inp;
        }
    }
    
    simulation();
    
    cout<<ans;
}
