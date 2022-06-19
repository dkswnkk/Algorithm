#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        unordered_map<int,int>umap;
        for(int i=0; i<n; i++){
            int inp; cin>>inp;
            umap[inp]++;
        }
        int m; cin>>m;
        for(int i=0; i<m; i++){
            int inp; cin>>inp;
            if(umap.find(inp)!=umap.end()) cout<<1<<'\n';
            else cout<<0<<'\n';
        }
    }
}
