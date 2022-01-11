class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int minCost = 0;
        
        for(int i = 0; i < sticks.size(); ++i)
        {
            minHeap.push(sticks[i]);
        }
        
        int root = minHeap.top();
        minHeap.pop();
        
        while(!minHeap.empty())
        {
            int curr = minHeap.top();
            minHeap.pop();
            minCost += (root + curr);
            
            minHeap.push(root + curr);
            root = minHeap.top();
            minHeap.pop();
        }
        
        return minCost;
    }
};