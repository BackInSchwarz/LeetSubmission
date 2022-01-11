class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        
        for (auto it: updates){
            q.push({ it[0], it[2]});
            q.push({ it[1]+1, -it[2]});
        }
        
        vector<int> ans(length, 0);
        
        int prev = 0;
        
        for (int i = 0 ; i < length; i++){
            while( !q.empty() && q.top().first <= i ){
                ans[i] +=q.top().second;
                q.pop();
            }
            ans[i]+= prev;
            prev = ans[i];
        }
        
        return ans;
    }
};