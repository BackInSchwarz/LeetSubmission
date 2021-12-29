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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>> ans;
        
        if (!root) return ans;
        
        map<int, map<int,vector<int>>> hm;
        
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0,0}});
        
        while(!q.empty()){
            int n = q.size();
            
            for (int i = 0; i< n; i++){
                TreeNode* cur = q.front().first;
                int column = q.front().second.first;
                int row = q.front().second.second;
                q.pop();
                
                hm[column][row].push_back(cur->val);
                
                if (cur->left) q.push({cur->left, {column-1, row+1}});
                if (cur->right) q.push({cur->right, {column+1, row+1}});
            }
            
        }
        

        
        for (auto [column, rowHm]:hm){
            vector<int> curAns;
            for (auto [row, list]:rowHm){
                sort(list.begin(), list.end());
                curAns.insert(curAns.end(), list.begin(), list.end());
            }
            
            ans.push_back(curAns);

        }
        
        return ans;
    }
};