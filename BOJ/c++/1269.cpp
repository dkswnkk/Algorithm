#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m; cin>>n>>m;
    int cnt = 0;
    unordered_map<int,int>umap1, umap2, umap3, umap4;
    
    for(int i=0; i<n; i++){
        int inp; cin>>inp;
        umap1[inp]++;
    }
    umap3 = umap1;
    for(int i=0; i<m; i++){
        int inp; cin>>inp;
        umap2[inp]++;
    }
    umap4 = umap2;
    
    for(auto it = umap2.begin(); it!=umap2.end(); it++) umap1[it->first]--;
    for(auto it = umap3.begin(); it!=umap3.end(); it++) umap2[it->first]--;
    
    
    for(auto it = umap1.begin(); it!=umap1.end(); it++){
        if(it->second == 1) cnt++;
    }
    for(auto it = umap2.begin(); it!=umap2.end(); it++){
        if(it->second == 1) cnt++;
    }
    cout<<cnt;
    
}

