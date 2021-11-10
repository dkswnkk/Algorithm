class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        for(int i=0; i<strs[0].length()+1; i++){
            string check = strs[0].substr(0,i);
            bool flag=true;
            for(int k=1; k<strs.size(); k++){
                if(strs[k].substr(0,i)!=check){
                    flag  = false;
                    break;
                }
            }
            if(flag) ans=check;
        }
        if(strs.size()==1) return strs.front();
        return ans;
    }
};
