#include <iostream>
#include <vector>
#include <memory.h>


using namespace std;

int N = 9;
int map[9][9];
vector<pair<int,int>> blank; // 0 좌표
bool flag = false;
int ans[9][9];


bool check(int a, int b) {
    
    //한줄 체크
    for (int i = 0; i < N; i++) {
        if (map[i][b] == map[a][b] && i != a) return false; //행 확인
        if (map[a][i] == map[a][b] && i != b) return false; //열 확인
    }
    
    int new_a = a/3*3;
    int new_b = b/3*3;
    
    for(int i = new_a; i<new_a+3; i++){
        for(int k = new_b; k<new_b+3; k++){
            if(a == i && b == k) continue;
            if(map[i][k] == map[a][b]) return false;
        }
    }
    return true;
}

void dfs(int idx){
    if(flag) return;
    
    if(idx == blank.size()){
        memcpy(ans, map, sizeof(map));
        flag = true;
        return;
    }
    
    int x = blank[idx].first;
    int y = blank[idx].second;
    for(int num = 1; num<=9; num++){
        map[x][y] = num;
        if(check(x,y)) dfs(idx+1);
        map[x][y] = 0;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    for(int i=0; i<N; i++){
        for(int k=0; k<N; k++){
            cin>>map[i][k];
            if(!map[i][k]) blank.push_back({i, k});
        }
    }
    dfs(0);
    
    for(int i=0; i<N; i++){
        for(int k=0; k<N; k++){
            cout<<ans[i][k] << ' ';
        }
        cout<<'\n';
    }
}
