class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int yesterday = prices[0];
        
        int ans = 0;
        
        for (int i =1;i<prices.size();i++){
            
            if(prices[i]>yesterday) ans+=(prices[i]-yesterday);
            
            yesterday = prices[i];
        }
        
        return ans;
    }
};