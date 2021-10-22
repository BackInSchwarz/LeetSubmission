class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro = INT_MIN;
        int curMin = INT_MAX;
        for (int i = 0; i<prices.size();i++){
            curMin = min(curMin, prices[i]);
            maxPro = max(maxPro, prices[i]-curMin);
        }
        
        return maxPro;
    }
};