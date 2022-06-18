#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N; cin>>N;
    string name;
    unordered_map<string,int> umap;
    for(int i=0; i<N; i++){
        cin>>name;
        umap[name]++;
    }
    for(int i=0; i<N-1; i++){
        cin>>name;
        umap[name]--;
    }
    for(auto it = umap.begin(); it!=umap.end(); it++){
        if(it->second!=0) cout<<it->first<<'\n';
    }
}
