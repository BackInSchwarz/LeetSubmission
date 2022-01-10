class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        
        long long h_max = 0;
        long long prev = 0;
        
        for (int i = 0 ; i < horizontalCuts.size(); i++){
            h_max = max(h_max, horizontalCuts[i] - prev);
            prev = horizontalCuts[i];
        }
        
        long long w_max = 0;
        prev = 0;
        
        for (int i = 0 ; i < verticalCuts.size(); i++){
            w_max = max(w_max, verticalCuts[i] - prev);
            prev = verticalCuts[i];
        }
        
        long long ans = h_max * w_max % 1000000007;
        
        return ans;
    }
};