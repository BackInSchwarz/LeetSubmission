class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int height = triangle.size();
        for (int i = 1; i <height; i++){

            for (int j = 0; j<=i; j++){
                if (j==0){
                    triangle[i][j] += triangle[i-1][j];
                    continue;
                }
                    
                if (j==i){
                    triangle[i][j] += triangle[i-1][j-1];
                    continue;
                }
                triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
            }
        }
        sort(triangle[height-1].begin(), triangle[height-1].end());
        
        return triangle[height-1][0];
    }
};