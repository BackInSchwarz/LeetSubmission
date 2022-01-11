class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> q;
        
        for (auto it:sticks){
            q.push(it);
        }
        
        int ans = 0;
        
        while(q.size()!=1){
            int first = q.top();
            q.pop();
            int second = q.top();
            q.pop();
            q.push(first+second);
            ans+=first+second;
        }
        
        return ans;
    }
};