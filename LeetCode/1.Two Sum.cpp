class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        unordered_map<int,int>m;
        
        for(int i=0; i<nums.size(); i++){
            int curr=target-nums[i];
            auto it=m.find(curr);
            if (it != m.end()){
                ans.push_back(m[curr]);
                ans.push_back(i);
                return ans;
            } 
            else m[nums[i]] = i;
        }
      return ans;
    }
};
