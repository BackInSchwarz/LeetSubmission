class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int Red=0;
        int Blue=0;
        int Green=0;
        
        for(auto cost:costs){
            int tempRed = min(Blue, Green)+ cost[0];
            int tempBlue = min(Red, Green)+ cost[1];
            int tempGreen = min(Blue, Red)+ cost[2];
            
            Red = tempRed;
            Blue = tempBlue;
            Green = tempGreen;
        }
        
        return min(Green, min(Red, Blue));
    }
};