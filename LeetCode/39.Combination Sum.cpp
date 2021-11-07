class Solution {
    map<vector<int>,int>duplicate;
    
public:
    vector<vector<int>>ans;
    void dfs(vector<int> &candidates,int &target,int sum,vector<int> route){
        if(sum==target){
            sort(route.begin(),route.end());
            if(duplicate[route]==0){
                duplicate[route]++;
                ans.push_back(route);
                return;
            }
        }
        else if(sum>target) return;
        else{
            for(int i=0; i<candidates.size(); i++){
                vector<int>temp(route);
                temp.push_back(candidates[i]);
                dfs(candidates,target,sum+candidates[i],temp);
            }
        }
        return;
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates,target,0,{});
        sort(ans.begin(),ans.end());
        
        
        return ans;
    }
};
