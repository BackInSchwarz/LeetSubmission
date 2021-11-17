class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        //brute force-- back tracking take one then move on to the next iteration
        //improved. sorted array. break if the remain is less than the value. 
        //dp-backsack??
        //longest subsequence with sum target. 
        sort(costs.begin(), costs.end());
        int ans = 0;
        for(int i =0;i<costs.size();i++){
            if (costs[i]<=coins){
                coins-=costs[i];
                ans++;
            }else{
                break;
            }
        }
        
        return ans;
    }
};