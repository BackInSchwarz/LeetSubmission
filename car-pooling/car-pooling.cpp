class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<vector<int>> events;
        for (auto trip:trips){
            events.push_back({trip[1], trip[0]});
            events.push_back({trip[2], -trip[0]});
        }
        
        int ans = 0;
        sort(events.begin(), events.end());
        for (auto event:events){
            ans = ans+event[1];
            if (ans>capacity) return false;
        }
        
        
        return true;
    }
};