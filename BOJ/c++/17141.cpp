#include <iostream>
#include <queue>
#include <memory.h>
#include <algorithm>
#include <map>
using namespace std;


int N, M;
int maps[51][51], cpy[51][51];
vector<pair<int,int>>virus;
vector<vector<pair<int,int>>>pick_virus;


int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int ans = 1e9;

map<vector<pair<int,int>>,int>dup;
void ncr(int index, vector<pair<int,int>>pick, int cnt){    //조합
    if(cnt==M){
        pick_virus.push_back(pick);
    }
    for(int i=index; i<virus.size(); i++){
        int x = virus[i].first;
        int y = virus[i].second;
        pick.push_back({x,y});
        ncr(i+1, pick, cnt+1);
        pick.pop_back();
    }
}


void bfs(){
    queue<pair<int,int>>q;
    int time_check[51][51] = {0, };
    
    for(int i=0; i<N; i++){
        for(int k=0; k<N; k++){
            if(cpy[i][k]==2){
                q.push({i,k});
            }
        }
    }
    
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0&&nx<N&&ny>=0&&ny<N){
                if(cpy[nx][ny]==0){
                    q.push({nx,ny});
                    time_check[nx][ny] = time_check[x][y] + 1;
                    cpy[nx][ny] = 2;
                }
            }
        }
    }
    
    bool flag = true;
    for(int i=0; i<N; i++){
        for(int k=0; k<N; k++){
            if(cpy[i][k]==0) flag = false;
        }
    }
    
    if(flag){
        int temp = -1;
        for(int i=0; i<N; i++){
            for(int k=0; k<N; k++){
                temp = max(temp, time_check[i][k]);
            }
        }
        ans = min(ans, temp);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int k=0; k<N; k++){
            cin>>maps[i][k];
            if(maps[i][k]==2){
                virus.push_back({i,k});
                maps[i][k] = 0;
            }
        }
    }
    
    ncr(0,{},0);
    
    for(int i=0; i<pick_virus.size(); i++){
        memcpy(cpy, maps, sizeof(maps));
        
        for(int k=0; k<pick_virus[i].size(); k++){
            int x = pick_virus[i][k].first;
            int y = pick_virus[i][k].second;
            cpy[x][y] = 2;
        }
        
        bfs();
    }
    
    if(ans==1e9) cout<<-1;
    else cout<<ans;
    
}
