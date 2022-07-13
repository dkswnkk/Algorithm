#include <iostream>
#include <regex>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s; cin>>s;
    
    s = regex_replace(s, regex("XXXX"), "AAAA");
    s = regex_replace(s, regex("XX"), "BB");
    
    if(s.find("X") != -1) cout<<"-1";
    else cout<<s;
}
