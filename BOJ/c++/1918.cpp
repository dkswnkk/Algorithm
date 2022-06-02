#include <iostream>
#include <stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s, ans; cin>>s;
    stack<char>st;
    for(char c: s){
        if(c=='(') st.push(c);
        else if(c==')'){
            while(st.top()!='('){
                cout<<st.top();
                st.pop();
            }
            st.pop();
        }
        else if(c =='*'|| c =='/' || c =='+' || c=='-'){
            if(c=='*'|| c=='/'){
                while(!st.empty() && (st.top()=='*' || st.top() == '/')){
                    cout<<st.top();
                    st.pop();
                }
                st.push(c);
            }
            else{
                while(!st.empty() && st.top()!='('){
                    cout<<st.top();
                    st.pop();
                }
                st.push(c);
            }
        }
        else cout<<c;
        
    }
    while(!st.empty()){
        if(st.top()!='(') cout<<st.top();
        st.pop();
    }
}
