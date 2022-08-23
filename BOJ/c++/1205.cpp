#include <iostream>
#include <map>
#define ll long long

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ll N, score, P; cin>>N>>score>>P;
    map<ll, ll, greater<ll>> m;
    
    for(int i=0; i<N; i++){
        ll inp; cin>>inp;
        m[inp]++;
    }
    
    int rank = 0;
    int same_score = 0;
    bool flag = false;
    for(auto it = m.begin(); it != m.end(); it++){
        if(it -> first >= score){
            if(it -> first == score){
                flag = true;
                same_score += it->second;
            }
            rank += it ->second;
        }
    }
    
    if(rank+1<=P || m.empty()){
        if(flag) cout<<rank+1 - same_score;
        else cout<<rank+1;
    }
    else cout<<-1;
}
