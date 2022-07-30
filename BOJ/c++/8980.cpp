#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Info{
    int from;
    int to;
    int box;
};

vector<Info>v;
int box[10001];

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
        
        // 해당 구간에 가장 많이 적재된 양 찾음
        for(int k=v[i].from; k<v[i].to; k++){
            cnt = max(box[k], cnt);
        }
        
        // 상자의 최대 적재량을 넘길 수 있기 때문에 지금 보고 있는 상자의 개수와 남은 용량 중 작은 것을 선택
        int add = min(v[i].box, C-cnt);
        
        for(int k=v[i].from; k<v[i].to; k++){   // 해당 구간에 적재된 것을 갱신한다.
            box[k] += add;
        }
        
        // 트럭에 더 적재 할 수 있는 양을 찾아 적재한다.
        ans += add;
    }
    
    cout<<ans;
    
}
