#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s; cin>>s;
    stack<char>st;
    int ans = 0;
    
    for(int i=0; i<s.length(); i++){
        if(s[i]=='(') st.push(s[i]);
        else if(s[i]==')'&&s[i-1]=='('){
            st.pop();
            ans += st.size();
        }
        else{
            st.pop();
            ans++;
        }
    }
    cout<<ans;
}
