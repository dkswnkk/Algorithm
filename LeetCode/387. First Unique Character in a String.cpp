class Solution {
public:
    int firstUniqChar(string s) {
        map<int,int> duplicate;
        int ans = 1e9;
       
        for(int i=0; i<s.length(); i++){
            duplicate[s[i]]++;
        }
        
        for(int i=0; i<s.length(); i++){
            if(duplicate[s[i]]==1){
                ans = min(ans, i);
            }
        }
        
        if(ans==1e9) return -1;
        return ans;
        

    }
};
