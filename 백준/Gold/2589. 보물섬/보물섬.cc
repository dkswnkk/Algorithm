#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int L, W;
char map[51][51];
int cost[51][51];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

vector<pair<int,int>> pos;
int ans = 0;


void find_ans(){
    for(int i=0; i<L; i++){
        for(int k=0; k<W; k++){
            if(cost[i][k] > ans){
                ans = cost[i][k];
            }
        }
    }
}

void bfs(int fx, int fy){
    queue<pair<int,int>> q;
    q.push({fx, fy});
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 && ny >=0 && nx < L && ny < W){
                if(cost[nx][ny] == 0 && map[nx][ny] == 'L' && !(fx == nx && ny == fy)){
                    cost[nx][ny] = cost[x][y] + 1;
                    q.push({nx,ny});
                }
            }
        }
    }
}


void init(){
    for(int i=0; i<L; i++){
        for(int k=0; k<W; k++){
            cost[i][k] = 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>L>>W;
    
    for(int i=0; i<L; i++){
        string s; cin>>s;
        for(int k=0; k<s.length(); k++){
            map[i][k] = s[k];
        }
    }
    
    for(int i=0; i<L; i++){
        for(int k=0; k<W; k++){
            if(map[i][k] == 'L'){
                pos.push_back({i, k});
            }
        }
    }
    
    for(auto &c: pos){
        int x = c.first;
        int y = c.second;
        bfs(x, y);
        find_ans();
        init();
    }
    cout<<ans;
}
