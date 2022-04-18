#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;


bool isOk(string s){
    stack<char> st;
    for(char c : s){
        if(c==']'||c==')'||c=='}'){
            if(st.empty()) return false;
            else if(c==']'&&st.top()=='[') st.pop();
            else if(c==')'&&st.top()=='(') st.pop();
            else if(c=='}'&&st.top()=='{') st.pop();
        }
        else st.push(c);
    }
    if(st.empty()) return true;
    return false;
}

int solution(string s) {
    int answer = 0;
    
    int len = s.length();
    
    while(len--){
        if(isOk(s)) answer++;
        string new_str = "";
        char s_back = s.front();
        new_str = s.substr(1,s.length()+1) + s_back;
        s = new_str;
    }
    
    return answer;
}
