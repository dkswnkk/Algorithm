#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> v;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, M, L, K; cin>>N>>M>>L>>K;
    for(int i=0; i<K; i++){
        int a, b; cin>>a>>b;
        v.push_back({a,b});
    }
    
    int max_cnt = 0;
    for(int i=0; i<K; i++){
        for(int j=0; j<K; j++){
            int x = v[i].first;
            int y = v[j].second;
            int cnt = 0;
            for(int k=0; k<K; k++){ // 포함되는 좌표 갯수 판별
                int nx = v[k].first;
                int ny = v[k].second;
                if(nx>=x && ny >= y && x+L>=nx && y+L>=ny) cnt++;
            }
            max_cnt = max(max_cnt, cnt);
        }
    }
    cout<<K - max_cnt;
}
