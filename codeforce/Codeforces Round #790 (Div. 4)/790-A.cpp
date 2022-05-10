#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin>>n;
    while(n--){
        string inp; cin>>inp;
        if(inp[0]-'0'+inp[1]-'0'+inp[2]-'0' == inp[5]-'0'+inp[4]-'0'+inp[3]-'0') cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
}
