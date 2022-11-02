#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <memory.h>
#define INF 1e9

using namespace std;

int N;
int map[126][126];
int d[126][126];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

void dijkstra(){
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
    pq.push({map[0][0], {0,0}});
    d[0][0] = map[0][0];
    
    while(!pq.empty()){
        int dist = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 && nx<N && ny>=0 && ny<N){
                int cost = dist + map[nx][ny];
                if(cost < d[nx][ny]){
                    d[nx][ny] = cost;
                    pq.push({cost,{nx, ny}});
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T = 0;
    while(cin>>N){
        T++;
        if(N==0) break;
        for(int i=0; i<N; i++){
            for(int k=0; k<N; k++){
                cin>>map[i][k];
            }
        }
        
        for(int i=0; i<126; i++){
            for(int k=0; k<126; k++){
                d[i][k] = INF;
            }
        }
        
        dijkstra();
        
        cout<<"Problem "<<T<<": "<< d[N-1][N-1]<<'\n';
        memset(d, 0, sizeof(d));
        memset(map, 0, sizeof(map));
        
    }
}
