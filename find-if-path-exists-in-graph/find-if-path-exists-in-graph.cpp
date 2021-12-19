class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        unordered_map<int, vector<int>> graph;
        
        for (auto e: edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        vector<bool> visited(n,0);
        
        stack<int> stk;
        stk.push(start);
        visited[start] = 1;
        
        while(!stk.empty()){
            auto cur = stk.top();
            stk.pop();
            if (cur == end)
                return true;
            for (auto e:graph[cur]){
                if (!visited[e]){
                    stk.push(e);
                    visited[e]=1;
                }
            }
        }
        
        return false;
    }
};

