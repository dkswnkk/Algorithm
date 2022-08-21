#include <iostream>
#include <vector>

using namespace std;


int N, K, ans;
vector<int> v;

bool visited[9];

void dfs(int depth, int power){
    
    if(depth == N-1 && power>=500){
        ans++;
        return;
    }
    
    for(int i=0; i<N; i++){
        if(visited[i]) continue;
        visited[i] = 1;
        if(power - K + v[i] >=500) dfs(depth+1, power - K + v[i]);
        visited[i] = 0;
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N>>K;
    for(int i=0; i<N; i++){
        int inp; cin>>inp;
        v.push_back(inp);
    }
    
    dfs(0, 500);
    cout<<ans;
    
}
