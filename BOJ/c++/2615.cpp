#include <iostream>
#include <vector>

using namespace std;

int N = 19;
int map[19][19];
vector<pair<int,int>> coor;

/*
 하단, 우측, 우상단, 우하단
 */

bool check(pair<int,int> _coor){  // 하단
    int r = _coor.first;
    int c = _coor.second;
    
    if(r <= 14 && map[r][c] != map[r-1][c]){    //  하단
        int cnt = 1;
        for(int i=r+1; i<r+1+4; i++){
            if(map[r][c] == map[i][c]) cnt++;
        }
        if(cnt == 5 && map[r+5][c] != map[r][c]) return true;
    }
    
    if(c <= 14 && map[r][c] != map[r][c-1]){    // 우측
        int cnt = 1;
        for(int i=c+1; i<c+1+4; i++){
            if(map[r][c] == map[r][i]) cnt++;
        }
        if(cnt == 5 && map[r][c+5] != map[r][c]) return true;
    }
    
    if(c <= 14 && r <= 14 && map[r+1][c-1] != map[r][c]){    // 우 상단
        int cnt = 1;
        int _r = r-1;
        for(int i=c+1; i<c+1+4; i++){
            if(map[r][c] == map[_r][i]) cnt++;
            _r--;
        }
        if(cnt == 5 && map[r-5][c+5] != map[r][c]) return true;
    }
    
    if(c <= 14 && r <= 14 && map[r][c] != map[r-1][c-1]){    // 우 하단
        int cnt = 1;
        int _r = r+1;
        for(int i=c+1; i<c+1+4; i++){
            if(map[r][c] == map[_r][i]) cnt++;
            _r++;
        }
        if(cnt == 5 && map[r+5][c+5] != map[r][c]) return true;
    }
    return false;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    for(int i=0; i<N; i++){
        for(int k=0; k<N; k++){
            cin>>map[i][k];
            if(map[i][k] != 0) coor.push_back({i, k});
        }
    }
    
    for(auto it: coor){
        if(check(it)){
            cout<< map[it.first][it.second] << '\n';
            cout<<it.first + 1 << ' '<<it.second + 1;
            return 0;
        }
    }
    cout<<0;
    
}
