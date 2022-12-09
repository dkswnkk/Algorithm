#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T; cin>>T;
    unordered_map<int, int> um, all;
    
    for(int i=1; i<=20; i++){
        all[i] = 1;
    }
    
    int ans = 0;
    while(T--){
        string cmd; cin>>cmd;
        if(cmd == "all"){
            ans++;
            um = all;
        }
        else if(cmd == "empty"){
            ans++;
            um.clear();
        }
        else if(cmd == "add"){
            int inp; cin>>inp;
            if(um.find(inp) == um.end()){
                um.insert({inp , 1});
                ans++;
            }
        }
        else if(cmd == "remove"){
            int inp; cin>>inp;
            if(um.find(inp) != um.end()){
                um.erase(inp);
                ans++;
            }
        }
        else if(cmd == "check"){
            int inp; cin>>inp;
            if(um.find(inp) != um.end()){
                cout<<1<<'\n';
                ans++;
            }
            else{
                cout<<0<<'\n';
                ans++;
            }
        }
        else if(cmd == "toggle"){
            int inp; cin>>inp;
            if(um.find(inp) != um.end()){
                um.erase(inp);
                ans++;
            }
            else{
                um.insert({inp, 1});
                ans++;
            }
        }
    }
}
