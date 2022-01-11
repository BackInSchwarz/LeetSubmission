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
    int ans;
    
    void helper(TreeNode* root, int prev){
        if (!root){
            return;
        } 
        
        int cur = prev*2 + root->val;
        
        if (!root->left && !root->right){
            ans+=cur;
        }else{
            helper(root->left, cur);
            helper(root->right, cur);
        }

        
        return;
    }
    
    int sumRootToLeaf(TreeNode* root) {
        
        ans = 0;
        
        helper(root,0);
        
        return ans;
    }
};