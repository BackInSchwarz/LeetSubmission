class Solution {
public:
    
    
    
    void dfs(vector<vector<int>>& image, int i, int j, int newColor, int target){
        
        
        if (i<0 || i>=image.size()) return;
        
        if (j<0 || j>=image[0].size()) return;
        
        
        if (image[i][j]==target){
            
            image[i][j] = newColor;
            
            dfs(image, i-1, j+0, newColor, target);
            dfs(image, i+1, j+0, newColor, target);
            dfs(image, i-0, j+1, newColor, target);
            dfs(image, i-0, j-1, newColor, target);
            
        }

        
        return;
        
    }
    
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        if (image[sr][sc] == newColor) return image;
        
        dfs(image, sr, sc, newColor, image[sr][sc]);
        
        
        return image;
        
    }
};