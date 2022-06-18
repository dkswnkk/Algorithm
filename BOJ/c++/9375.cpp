#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T; cin>>T;
    while(T--){
        unordered_map<string, vector<string>> umap;
        int cnt = 1;
        int n; cin>>n;
        for(int i=0; i<n; i++){
            string a, b; cin>>a>>b;
            umap[b].push_back(a);
        }
        
        for(auto it = umap.begin(); it!=umap.end(); it++){
            cnt *= it->second.size()+1; //의상 종류 갯수 + 그 의상을 입지 않았을 경우(1)
        }
        cout<<cnt-1<<'\n';  //둘다 안입은 경우 뺌
    }
}
