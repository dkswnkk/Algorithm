#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Info{
    int from;
    int to;
    int weight;
};

vector<Info>v;
int trunk[10001];

const bool cmp(Info &i1, Info &i2){
    if(i1.to == i2.to) return i1.from < i2.from;
    else return i1.to < i2.to;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, C, M; cin>>N>>C>>M;
    
    for(int i=0; i<M; i++){
        int from, to, cnt; cin>>from>>to>>cnt;
        v.push_back({from, to, cnt});
    }
    sort(v.begin(), v.end(), cmp);
    
    int ans = 0;
    
    for(int i=0; i<v.size(); i++){
        int cnt = 0;
        for(int k=v[i].from; k<v[i].to; k++){
            cnt = max(trunk[k], cnt);
        }
        
        ans += min(v[i].weight, C - cnt);
        for(int k=v[i].from; k<v[i].to; k++){   // 박스를 싣는다.
            trunk[k] += min(v[i].weight, C-cnt);
        }
    }
    cout<<ans;
    
}
