class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0;
        int end = height.size()-1;
        
        int ans = -1;
        while(start<=end){
            int x = end-start;
            int y = min(height[start],height[end]);
            ans = max(ans,x*y);
            
            if(height[start]<height[end]) start++;
            else end--;
        }
        return ans;
    }
};
