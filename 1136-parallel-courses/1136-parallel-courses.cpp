class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<int> inCount(n+1, 0);
        vector<vector<int>> graph(n+1);
        
        for (auto& r: relations){
            graph[r[0]].push_back(r[1]);
            inCount[r[1]]++;
        }
        
        int step =0;
        int studiedCount = 0;
        vector<int> bfsQueue;
        
        for (int node = 1; node<=n; node++ ){
            if (inCount[node] ==0)
                bfsQueue.push_back(node);
        }
        
        while(!bfsQueue.empty()){
            step++;
            vector<int> nextQueue;
            for (auto& node: bfsQueue){
                studiedCount++;
                for( auto& endNode: graph[node]){
                    inCount[endNode]--;
                    if (inCount[endNode] == 0){
                        nextQueue.push_back(endNode);
                    }
                }
            }
            bfsQueue = nextQueue;
        }
        
        return studiedCount == n? step: -1;
    }
};