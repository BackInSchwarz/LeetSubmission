class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //3:38pm
        priority_queue<vector<int>> pq;
        for (int i = 0;i<points.size();i++){
            int x = points[i][0];
            int y = points[i][1];
            // cout<<x*x + y*y<<endl;
            int dist = x*x + y*y;
            // cout<<dist<<endl;
            // float fi=i;
            pq.push({-dist, i});
        }
        int curk=0;
        vector<vector<int>> ans;
        while(curk<k){
            vector<int> curAns=pq.top();
            pq.pop();
            int index = curAns[1];
            ans.push_back(points[index]);
            curk++;
        }
        
        return ans;
    }
};