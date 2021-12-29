/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        
        if (!root) return ans;
        
        map<int, vector<int>> hm;
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        
        while(!q.empty()){
            int n = q.size();
            
            for (int i = 0; i< n; i++){
                TreeNode* cur = q.front().first;
                int column = q.front().second;
                q.pop();
                
                hm[column].push_back(cur->val);
                
                if (cur->left) q.push({cur->left, column-1});
                if (cur->right) q.push({cur->right, column+1});
            }
            
        }
        

        
        for (auto it:hm){
            ans.push_back(it.second);
        }
        
        return ans;
        
    }
};