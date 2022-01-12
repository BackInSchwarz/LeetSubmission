class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<float, int>> q;
        
        for (int i = 0; i < points.size(); i++){
            int x = points[i][0];
            int y = points[i][1];
            q.push({sqrt( x * x + y * y ), i});
            
            while(q.size()>k){
                q.pop();
            }
        }
        
        vector<vector<int>> ans;
        
        while( !q.empty() ){
            ans.push_back( points[q.top().second]);
            q.pop();
        }
        
        
        return ans;
    }
};