#include <iostream>
#include <vector>
#include <map>

using namespace std;


int N,M,ans;
vector<pair<int,int>>fr_pair;

void init(){
    ans=0;
    fr_pair.clear();
}

void dfs(int peo_link_cnt, int peo_index, map<int,int>m){
    if(peo_link_cnt==N/2){  // 쌍이기 때문에 한번에 두 사람이 맺어짐. 따라서 총 사람/2
        for(auto it=m.begin(); it!=m.end(); it++){
            if(it->second==0) return;   // 친구가 안맺어진 사람이 있다면 return
        }
        ans++;  // 한명도 빠짐없이 모든 학생을 친구끼리 짝지어졌을 때
        return;
    }
    
    for(int i=peo_index; i<M; i++){
        int peo_1=fr_pair[i].first;
        int peo_2=fr_pair[i].second;
        if(m[peo_1]==1||m[peo_2]==1) continue;  // 둘 중 한명이 이미 짝 지어진 친구라면 돌지않음.
        m[peo_1]=1, m[peo_2]=1; // 서로 친구가 맺어짐
        dfs(peo_link_cnt+1,i+1,m);  //계속 탐색
        m[peo_1]=0, m[peo_2]=0;
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T; cin>>T;
    
    while(T--){
        cin>>N>>M;
        init();
        
        vector<pair<int,int>>pair_check;
        map<int,int>m;
        for(int i=0; i<N; i++) m[i]=0;  // 학생번호를 키값으로 등록
        for(int i=0; i<M; i++){ // 친구 쌍의 갯수만큼 입력받음
            int a,b; cin>>a>>b;
            fr_pair.push_back({a,b});   // 친구 쌍 입력
        }
        
        dfs(0,0,m);
        
        cout<<ans<<'\n';
    }
}
