#include <iostream>
#include <vector>
#define ll long long

using namespace std;


ll gcd(ll a, ll b){
    if(b==0) return a;
    else return gcd(b,a%b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ll N,K; cin>>K>>N;
    
    vector<ll>v;
    for(int i=0; i<N; i++){
        ll num; cin>>num;
        v.push_back(num);
    }
    
    ll num = v[0];
    ll lcm_val = 0;
    
    for(int i=0; i<N; i++){
        lcm_val = (num*v[i]) / gcd(num,v[i]);
        num = lcm_val;
    }
    cout<<num-K;
    
}
