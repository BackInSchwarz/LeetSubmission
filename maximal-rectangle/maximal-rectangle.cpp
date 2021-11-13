class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        stk.push(-1);
        int max_area = 0;
        for (size_t i = 0; i < heights.size(); i++) {
            while (stk.top() != -1 and heights[stk.top()] >= heights[i]) {
                int current_height = heights[stk.top()];
                stk.pop();
                int current_width = i - stk.top() - 1;
                max_area = max(max_area, current_height * current_width);
            }
            stk.push(i);
        }
        while (stk.top() != -1) {
            int current_height = heights[stk.top()];
            stk.pop();
            int current_width = heights.size() - stk.top() - 1;
            max_area = max(max_area, current_height * current_width);
        }
        return max_area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int r = matrix.size();
        if(r==0) return 0;
        int c = matrix[0].size();
        vector<int> dp(c,0);
        for(int i =0;i<c;i++){
            if(matrix[0][i]=='1'){
                dp[i]=1;
            }else{
                dp[i]=0;
            }
        }
        int ans = largestRectangleArea(dp);
        
        for(int i=1;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]=='0'){
                    dp[j]=0;
                }else{
                    dp[j]+=1;
                }
            }
            ans = max(ans, largestRectangleArea(dp));
        }
        return ans;
    }
};