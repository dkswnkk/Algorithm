class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size();
        int ans = 0;
        
        sort(nums.begin(),nums.end());
        
        while(start<=end){
            int mid = (start+end)/2;
            if(mid>=nums.size()) break;
            if(target == nums[mid]){
                ans = mid;
                break;
            }
            else if(target>nums[mid]){
                if(mid+1<nums.size()){
                    if(target<nums[mid+1]){
                        ans = mid+1;
                        break;
                    }
                }
                start = mid+1;
                
            }
            else{
                if(mid-1>=0){
                    if(target>nums[mid-1]){
                        ans = mid;
                        break;
                    }
                }
                end = mid-1;
            }
        }
        if(target>nums.back()&&ans==0) ans = nums.size();
        else if(target>nums.front()&&ans==0) ans = 1;
        return ans;
    }
};
