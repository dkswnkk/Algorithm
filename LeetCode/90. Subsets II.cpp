class Solution {
public:
    map<vector<int>,int>visited;
    vector<vector<int>>ans;
    
    void dfs(int num, vector<int>&nums,vector<int>current){
        
        sort(current.begin(),current.end());
        if(!visited[current]){
            ans.push_back(current);
            visited[current]=1;
        }
        
        if(num>nums.size()) return;
  
        for(int i=num; i<nums.size(); i++){
            vector<int>temp=current;
            temp.push_back(nums[i]);
            dfs(i+1,nums,temp);
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            dfs(i,nums,{});
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
