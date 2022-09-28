#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N; cin>>N;
    string s; cin>>s;
    
    int ans = 0;
    for(int i=1; i<s.length(); i++){
        if(s[i] == 'W' && s[i - 1] == 'E') ans++;
    }
    cout<<ans;
}
