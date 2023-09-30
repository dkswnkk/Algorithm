#include <iostream>
#include <vector>
#include <memory.h>
#include <queue>
#define INF 1e9

using namespace std;

int W, H;
char map[101][101];

vector<pair<int,int>> pos;

int cost[101][101];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(int x, int y){
    queue<pair<int,int>> q;
    q.push({x, y});
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            while(nx >= 0 && nx < H && ny >= 0 && ny < W && map[nx][ny] != '*'){
                if(cost[nx][ny] == 0){
                    cost[nx][ny] = cost[x][y] + 1;
                    q.push({nx, ny});
                }
                nx = nx + dx[i];
                ny = ny + dy[i];
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> W >> H;
    for(int i=0; i<H; i++){
        string inp; cin>>inp;
        for(int k=0; k<inp.size(); k++){
            map[i][k] = inp[k];
            if(map[i][k] == 'C'){
                pos.push_back({i,k});
            }
        }
    }
    bfs(pos.front().first, pos.front().second);
    
    cout<<cost[pos.back().first][pos.back().second] - 1;
}
