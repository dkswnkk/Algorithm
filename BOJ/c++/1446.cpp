#include <iostream>
#include <algorithm>
#include <vector>
#define INF 1e9
using namespace std;

vector<pair<int,int>>v[10001];
int dist[10001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, D; cin>>N>>D;
    for(int i=0; i<N; i++){
        int a, b, c; cin>>a>>b>>c;
        v[b].push_back({a, c}); // a에서 b까지 c만큼의 거리
    }
    
    fill(dist, dist+10001, INF);
    dist[0] = 0;
    for(int i=1; i<=D; i++){
        if(v[i].empty()) dist[i] = dist[i-1] + 1; // 해당 위치에서 시작하는 지름길이 존재하지 않을 경우 +1만큼 추가한다.
        else{
            for(auto next: v[i]){
                dist[i] = min({dist[i], dist[next.first] + next.second, dist[i-1]+1});
            }
        }
    }
    
    cout<<dist[D];
}
