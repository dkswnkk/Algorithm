#include <iostream>
#include <vector>
using namespace std;

int N = 9;
int map[9][9];
vector<pair<int,int>> blank;
bool flag = false;

bool check(int r, int c){
    
    for(int i=0; i<9; i++){ // 가로, 세로 체크
        if(i!=c && map[r][i] == map[r][c] && map[r][i] !=0) return false;
        if(i!=r && map[i][c] == map[r][c] && map[i][c] !=0) return false;
    }
    
    int _r = (r / 3) * 3;
    int _c = (c / 3) * 3;
    
    for(int i = _r; i<_r+3; i++){   // 3*3 체크
        for(int k = _c; k<_c+3; k++){
            if(i != r && k != c && map[r][c] == map[i][k] && map[i][k] != 0) return false;
        }
    }
    return true;
}

void backtracking(int idx){
    if(flag) return;
    if(idx == blank.size()){
        for(int i=0; i<N; i++){
            for(int k=0; k<N; k++){
                cout<<map[i][k];
            }
            cout<<'\n';
        }
        flag = true;
        return;
    }
    
    for(int i=1; i<=9; i++){
        int r = blank[idx].first;
        int c = blank[idx].second;
        map[r][c] = i;
        backtracking(idx+1);
        map[r][c] = 0;
    }
}

int main(){
    for(int i=0; i<N; i++){
        for(int k=0; k<N; k++){
            scanf("%1d", &map[i][k]);
            if(map[i][k] == 0) blank.push_back({i, k});
        }
    }
    
    backtracking(0);

}
