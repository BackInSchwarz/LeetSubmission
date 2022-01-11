class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> q;
        
        for (auto it:sticks){
            q.push(it);
        }
        
        int ans = 0;
        int first = 0;
        int second = 0;
        int sum = 0;
        
        while(q.size()!=1){
            first = q.top();
            q.pop();
            second = q.top();
            q.pop();
            sum = first + second;
            q.push(sum);
            ans+=sum;
        }
        
        return ans;
    }
};