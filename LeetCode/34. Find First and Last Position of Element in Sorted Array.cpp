class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int start = 0;
        int end = nums.size()-1;
        
        int first_index = -1,last_index = -1;
        vector<int>ans;
       
        while(start<=end){
            int mid = (start+end)/2;
            if(nums[mid]>target) end=mid-1;
            else if(nums[mid]<target) start=mid+1;
            else{
                first_index = last_index = mid;
                break;
            }
        }
        
        int index = first_index;
        
        while(--index>=0&&nums[index]==target) first_index--;
        
        index = last_index;
        
        while(++index<nums.size()&&nums[index]==target) last_index++;
        
        ans.emplace_back(first_index);
        ans.emplace_back(last_index);
        
        if(ans.size()==0||index == -1) return {-1,-1};
        return ans;
    }
};
