#include <string>
#include <stack>

using namespace std;

bool solution(string s){
    stack<char>st;
    for(char c:s){
        if(c==')'){
            if(st.empty()) return false;
            else if(st.top()=='(') st.pop();
        }
        else st.push(c);
    }
    if(st.empty()) return true;
    return false;
}
