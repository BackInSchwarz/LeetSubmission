class Solution {
public:
    vector<vector<int>> ans;
    
    void dfs(vector<vector<int>>& graph, int curNode, vector<int>& curAns){
        int lastNode = graph.size() - 1;
        if (curNode == lastNode){
            ans.push_back(curAns);
            return;
        }
        
        for (auto node:graph[curNode]){
            curAns.push_back(node);
            dfs(graph, node, curAns);
            curAns.pop_back();
        }
        
        return;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        ans.clear();
        
        vector<int> curAns(0);
        
        curAns.push_back(0);
        
        dfs(graph, 0, curAns);
        
        
        return ans;
    }
};