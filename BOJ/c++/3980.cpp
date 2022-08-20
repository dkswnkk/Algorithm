#include <iostream>
#include <memory.h>

using namespace std;

int map[11][11];
int ans;
int visited[11];

void dfs(int peo, int sum){
    
    if(peo == 11){
        ans = max(ans, sum);
        return;
    }
    
    for(int i=0; i<11; i++){
        if(map[peo][i] && !visited[i]){
            visited[i] = 1;
            dfs(peo+1, sum + map[peo][i]);
            visited[i] = 0;
        }
    }
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T; cin>>T;
    while(T--){
        for(int i=0; i<11; i++){
            for(int k=0; k<11; k++){
                cin>>map[i][k];
            }
        }
        
        dfs(0,0);
        cout<<ans<<'\n';
        ans = 0;
        memset(visited, 0, sizeof(visited));
    }
}
