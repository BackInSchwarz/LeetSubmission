class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size()==1) return 0;
        int maxPro = 0;
        int ydPrice = prices[0];
        for (int i =1;i<prices.size();i++){
            if (prices[i]>ydPrice) maxPro+=(prices[i] - ydPrice);
            ydPrice = prices[i];
        }
        
        return maxPro;
    }
};