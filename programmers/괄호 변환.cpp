#include <string>
#include <vector>
#include <stack>

using namespace std;

bool check_perfect(string u){   //올바른 괄호 문자열 체크
    stack<char>st;
    for(int i=0; i<u.length(); i++){
        if(u[i]=='(') st.push(u[i]);
        else{
            if(st.empty()) st.push(u[i]);
            else if(st.top()=='(') st.pop();
            else st.push(u[i]);
        }
    }
    if(st.empty()) return true;
    else return false;
}

string make(string s){
    string u,v;
    if(s.empty()||check_perfect(s)) return s;   //빈 문자열이거나 올바른 괄호 문자열이면 반환
    
    
    int right_cnt=0,left_cnt=0;
    bool flag=false;
    
    for(int i=0; i<s.length(); i++){
        if(!flag){
            if(s[i]=='(') right_cnt++;
            else left_cnt++;
            u+=s[i];
            if(right_cnt==left_cnt) flag=true;
        }
        else v+=s[i];
    }
    
    if(check_perfect(u)){   //u가 올바른 괄호 문자열 일경우
        return u+make(v);
    }
    else{   //u가 올바른 괄호 문자열이 아닐 경우
        string inp="("+make(v)+")";
        for(int i=0; i<u.length(); i++){
            if(i!=0&&i!=u.length()-1){
                if(u[i]=='(') inp+=')';
                else inp+='(';
            }
        }
        return inp;
    }
    return 0;
}

string solution(string p) {
    string answer = "";
    
    answer=make(p);
    return answer;
}
