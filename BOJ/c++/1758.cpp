#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N; cin>>N;
    vector<int>v(N);
    for(int i=0; i<N; i++) cin>>v[i];
    long long int ans = 0;
    sort(v.begin(),v.end(), greater<int>());
    for(int i=1; i<=v.size(); i++){
        int tip = v[i-1] - (i-1);
        ans += tip>=0?tip:0;
    }
    cout<<ans;
}
