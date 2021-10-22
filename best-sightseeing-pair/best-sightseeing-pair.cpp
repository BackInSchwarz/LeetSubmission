class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        // bruteforce: calculate every pair and find the max O(n^2)
        // improved: how to use the some known value to save time or space??
            //n == 2: straight forward
            //n == 3: 
        //identify optimal solution's property. 
            //
        //identify the means to build optimal solution incrementally.
        
        
        // add n == 2 retrun xxx
        
        int n = values.size();
        vector<int> l(n-1,0);
        vector<int> r(n-1,0);
        
        l[0] = values[0] + 0;
        r[n-2] = values[n-1]-(n-1);
        
        for (int i = 1; i <n-1;i++){
            l[i] = max(values[i] + i, l[i-1]);
        }
        
        for (int i = (n-2); i>=1;i--){
            r[i-1] = max(r[i], values[i]-i);
        }
        
        int ans=INT_MIN;
        for (int i = 0; i<n-1;i++){
            ans = max(ans, l[i] + r[i]);
        }
        
        return ans;
    }
};