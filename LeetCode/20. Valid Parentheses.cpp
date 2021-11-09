class Solution {
public:
    bool isValid(string s) {
        
        stack<char>st;
        
        for(int i=0; i<s.length(); i++){
            char inp = s[i];
            if(st.empty()) st.push(inp);
            else{
                char top = st.top();
                if(top=='('&&inp==')') st.pop();
                else if(top=='{'&&inp=='}') st.pop();
                else if(top=='['&&inp==']') st.pop();
                else st.push(inp);
            }
        }
        if(st.empty()) return true;
        else return false;
    }
};
