#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, M; cin>>N>>M;
    vector<int> v;
    for(int i=0; i<N; i++){
        int inp; cin>>inp;
        v.push_back(inp);
    }
    sort(v.begin(), v.end());
    for(int i=0; i<M; i++){
        int a, b; cin>>a>>b;
        int first = lower_bound(v.begin(), v.end(), a) - v.begin();
        int second = upper_bound(v.begin(), v.end(), b) - v.begin();
        cout<<second - first<<'\n';
    }
    
}
