#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int H, W; cin>>H>>W;
    vector<int> v;
    for(int i=0; i<W; i++){
        int inp; cin>>inp;
        v.push_back(inp);
    }
    
    int ans = 0;
    for(int i=0; i<v.size(); i++){
        int max_h = 0;
        int idx = 0;
        for(int k=i+1; k<v.size(); k++){
            if(v[k] > v[i]){
                if(max_h < v[i]){
                    max_h = v[i];
                    idx = k;
                }
                break;
            }
            if(max_h < v[k]){
                idx = k;
                max_h = v[k];
            }
        }
        for(int k = i+1; k<idx; k++){
            ans += max_h - v[k];
        }
        if(max_h != 0) i = idx - 1;
    }
    cout<<ans;
}
