#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N; cin>>N;
    vector<int> v;
    for(int i=0; i<N; i++){
        int inp; cin>>inp;
        v.push_back(inp);
    }
    int max_num = -1;
    int ans = 0;
    for(int i=v.size()-1; i>=0; i--){
        if(v[i] > max_num){
            max_num = v[i];
        }
        ans = max(ans, max_num - v[i]);
    }
    cout<<ans;
}
