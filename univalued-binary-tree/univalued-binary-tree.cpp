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
    bool isUnivalTree(TreeNode* root) {
        
        stack<TreeNode*> stk;
        stk.push(root);
        
        int val = root->val;
        
        while(!stk.empty()){
            
            TreeNode* cur = stk.top();
            stk.pop();
            
            if (cur->val!=val) return false;
            
            if (cur->left) stk.push(cur->left);
            if (cur->right) stk.push(cur->right);
            
            
        }
        
        return true;
    }
};