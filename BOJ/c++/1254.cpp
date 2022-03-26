#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


bool isPalindrom(string inp){
    string temp = inp;
    reverse(inp.begin(), inp.end());
    if(temp==inp) return true;
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s; cin>>s;
    int ans = 1e9;
    string temp = s;
    reverse(temp.begin(),temp.end());
    if(s==temp){
        cout<<s.length();
        return 0;
    }
    
    for(int i=0; i<s.length(); i++){
        string temp = s.substr(i,s.length());
        if(isPalindrom(temp)){
            int len = s.length()-temp.length();
            ans = min(ans, len);
        }
    }
    if(ans==1e9) cout<<s.length()*2;
    cout<<ans+s.length();
}

