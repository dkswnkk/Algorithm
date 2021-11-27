class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>m;
        for(int i:nums) m[i]++;
        
        int cnt=-1,ans;
        
        for(auto it=m.begin(); it!=m.end(); it++){
            if(it->second>cnt){
                cnt=it->second;
                ans=it->first;
            };
        } 
        return ans;
    }
};
