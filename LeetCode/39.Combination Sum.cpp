class Solution {
public:
    vector<vector<int>>ans;
    
    void dfs(int target,int index,vector<int>& candidates, vector<int>current){
        if(target==0) ans.push_back(current);
        
        for(int i=index; i<candidates.size(); i++){
            if(candidates[i]>target) break;
            current.push_back(candidates[i]);
            dfs(target-candidates[i],i,candidates,current);
            current.pop_back();
        }
    }
        
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        dfs(target,0,candidates,{});
        return ans;
    }
};
