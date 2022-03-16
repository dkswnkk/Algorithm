#include <iostream>
#include <stack>
#include <map>
using namespace std;

int main(){
    string s; cin>>s;
    stack<char>st;
    map<char,int>m;
    int ans = 0, temp = 1;
    
    for(int i=0; i<s.length(); i++) m[s[i]]++;
    if(m['[']!=m[']']||m['(']!=m[')']){
        cout<<0;
        return 0;
    }
    
    
    for(int i=0; i<s.length(); i++){
        if(s[i]=='('){
            temp *= 2;
            st.push('(');
        }
        else if(s[i]=='['){
            temp *= 3;
            st.push('[');
        }
        else if(s[i]==')'){
            if(st.empty()||st.top()=='['){
                ans = 0;
                break;
            }
            else if(s[i-1]=='('){
                ans+=temp;
                temp/=2;
                st.pop();
            }
            else{
                temp/=2;
                st.pop();
            }
        }
        else if(s[i]==']'){
            if(st.empty()||st.top()=='('){
                ans = 0;
                break;
            }
            else if(s[i-1]=='['){
                ans+=temp;
                temp/=3;
                st.pop();
            }
            else{
                temp/=3;
                st.pop();
            }
        }
    }
    cout<<ans;
}
