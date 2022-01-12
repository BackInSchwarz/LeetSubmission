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
    
    void helper(TreeNode* root, int val){
        if (!root) return;
        
        
        if (val<root->val){
            if (root->left){
                helper(root->left, val);
            }else{
                root->left = new TreeNode(val);
            }
            
        }
        
        if (val>root->val){
            if (root->right){
                helper(root->right, val);
            }else{
                root->right = new TreeNode(val);
            }
        }
        
        
        
        
        // helper(root->right, val);
        return;
    }
    
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root)
            return new TreeNode(val);
        
        
        helper(root, val);
        
        
        return root;
        
    }
};