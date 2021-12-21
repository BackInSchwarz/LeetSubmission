class Solution {
public:
    int target;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        stack<pair<int, vector<int>>> stk;
        
        stk.push({0, {}});
        
        int n = graph.size();
        int target = n-1;
        
        vector<vector<int>> ans;
        
        while(!stk.empty()){
            int curVal = stk.top().first;
            vector<int> curPath = stk.top().second;
            
            stk.pop();
            
            curPath.push_back(curVal);
            
            if (curVal == target)
            {
                ans.push_back(curPath);
                continue;
            }
            
            for (auto item: graph[curVal]){
                stk.push({item, curPath});
            }
            
        }
        
        return ans;
    }
};