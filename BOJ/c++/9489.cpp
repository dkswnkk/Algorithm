#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

int graph[1000001];
vector<int> idx;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    while(cin>>n>>k){
        if(n==0 && k==0) break;
        
        int parent_idx = -1, before = 0, ans = 0;
        for(int i=0; i<n; i++){
            int inp; cin>>inp;
            idx.push_back(inp);
            
            if(i==0){
                before = inp;
                graph[inp] = inp;
            }
            else{
                if(before+1 == inp){
                    graph[inp] = idx[parent_idx];
                    before = inp;
                }
                else{
                    before = inp;
                    graph[inp] = idx[++parent_idx];
                }
            }
        }
        for(int node: idx){
            if(graph[graph[node]] == graph[graph[k]] && graph[node] != graph[graph[k]] && graph[node]!= graph[k] && graph[k] != graph[idx[0]]) ans++;
        }     
        cout<<ans<<'\n';
        idx.clear();
        memset(graph,0,sizeof(graph));      
    }   
}
