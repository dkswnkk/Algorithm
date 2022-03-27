#include <iostream>
#include <vector>
#include <map>
using namespace std;


int N,M,ans;
vector<int>v[201];

void dfs(int now, int first, int second, int third, int cnt){
    if(cnt==3){
        for(int i=0; i<v[first].size(); i++){
            if(v[first][i] == second || v[first][i] == third) return;
        }
        for(int i=0; i<v[second].size(); i++){
            if(v[second][i] == first || v[second][i] == third) return;
        }
        for(int i=0; i<v[third].size(); i++){
            if(v[third][i] == first || v[third][i] == second) return;
        }
        ans++;
        return;
    }
    
    for(int i=now; i<N; i++){
        if(cnt==1) dfs(i+1,first,i+1,third,cnt+1);
        else if(cnt==2) dfs(i+1,first,second,i+1,cnt+1);
    }
    
    
    
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N>>M;
    
    for(int i=0; i<M; i++){
        int a, b; cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    for(int i=1; i<N; i++){
        dfs(i, i, -1, -1, 1);
    }
    cout<<ans;
}
