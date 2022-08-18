#include <iostream>
#include <vector>
using namespace std;

int N, M, ans;

int map[26][26];
int dx[3] = {-1,0,-1};
int dy[3] = {0,-1,-1};

bool check(int x, int y){
    int cnt = 0;
    for(int i = 0; i<3; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx>=0 && nx < N && ny>=0 && ny< M){
            if(map[nx][ny]) cnt++;
        }
    }
    if(cnt == 3) return false;
    return true;
}


void backtracking(int x, int y){
    
    if(x == N-1 && y == M){
        ans++;
        return;
    }
    
    if(y == M){
        y = 0;
        x++;
    }
    
    map[x][y] = 1;
    if(check(x, y)) backtracking(x, y+1);   // 2*2가 안 만들어질때 넴모를 올린다.
    map[x][y] = 0;
    backtracking(x, y+1);   // 현재칸에는 넴모를 올리지않고 넘어간다.
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N>>M;

    backtracking(0,0);
    
    cout<<ans;
}
