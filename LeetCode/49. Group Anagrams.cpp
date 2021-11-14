class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<string,vector<string>>m;
        map<char,int>char_check;
        
        sort(strs.begin(),strs.end());
        
        vector<string>temp = strs;
        
        for(int i=0; i<temp.size(); i++){
            sort(temp[i].begin(),temp[i].end());
            m[temp[i]]={};
        }
        vector<string> origin = strs;
        
        for(int i=0; i<strs.size(); i++){
            sort(strs[i].begin(),strs[i].end());
            m[strs[i]].push_back(origin[i]);
        }
        
        vector<vector<string>>ans;
        
        for(auto i = m.begin(); i!=m.end(); i++){
            ans.push_back(i->second);
        }
        
      return ans;
    }
};
