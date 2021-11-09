class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_index,min_value=1e9,ans;
        
        for(int i=0; i<prices.size(); i++){
            if(prices[i]<min_value){
                min_value = prices[i];
            }
            else{
                ans = max(-min_value+prices[i],ans);
            }
        }
        if(ans<0) return 0;
        return ans;
    }
};
