#include <iostream>
#include <vector>
#define ll long long int
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ll N, K; cin>>N>>K;
    vector<ll> v;
    for(int i=0; i<N; i++){
        int inp; cin>>inp;
        v.push_back(inp);
    }

    
    ll d = 0;
    for(int i=0; i<N; i++){
        d += v[i];
        if(d > K){
            cout << i + 1;
            return 0;
        }
    }
    
    for(int i=N-1; i>=0; i--){
        d += v[i];
        if(d > K){
            cout << i + 1;
            return 0;
        }
    }

}
