class Solution {
public:
    int lengthOfLastWord(string s) {
        
        vector<string>parsing;
        
        string temp;
        
        for(int i=0; i<s.length()+1; i++){
            if(s[i]!=' '&&s[i]!='\0') temp+=s[i];
            else{
                parsing.push_back(temp);
                temp.clear();
            }
        }
        reverse(parsing.begin(),parsing.end());
        
        for(string s:parsing){
            if(s.length()!=0) return s.length();
        }
        return 0;
    }
};
