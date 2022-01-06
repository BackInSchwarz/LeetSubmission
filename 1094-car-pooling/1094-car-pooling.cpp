class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<vector<int>> schedule;
        
        for (auto trip:trips){
            schedule.push_back({trip[1], trip[0]});
            schedule.push_back({trip[2], -trip[0]});
        }
        
        sort(schedule.begin(), schedule.end());
        
        int curNum = 0;
        
        for (auto it:schedule){
            curNum +=it[1];
            
            if (curNum>capacity)
                return false;
                
        }
        
        return true;
    }
};