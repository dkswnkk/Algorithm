#include <iostream>
#include <vector>
#define ll long long int
using namespace std;

ll N,K,ans;
vector<char>v;

void find(vector<char>v, string now){
    if(!now.empty()){
        if(stoll(now)<=N) ans = max(ans, stoll(now));
        else return;
    }
    
    for(int i=0; i<K; i++){
        now+=v[i];
        find(v, now);
        now.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); 
    
    cin>>N>>K;
    
    for(int i=0; i<K; i++){
        char inp; cin>>inp;
        v.push_back(inp);
    }
    find(v, "");
    cout<<ans;
}
