#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, w; cin>>n>>w;
    ll coin = 0;
    vector<int>v(n+1);
    for(int i=0; i<n; i++) cin>>v[i];
    
    for(int i=0; i<n; i++){
        if(v[i]<v[i+1]){    // 코인 구매
            coin += w/v[i];
            w = w%v[i];
        }
        else{   // 코인 판매
            w += v[i]*coin;
            coin = 0;
        }
    }
    cout<<w;

}
