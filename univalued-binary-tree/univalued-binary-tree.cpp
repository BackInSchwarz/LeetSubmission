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
    int theVal;
    
    bool helper(TreeNode* root, int theVal){
        if(!root) return true;
        
        if(root->val!=theVal) return false;
        
        return helper(root->left, theVal)&&helper(root->right, theVal);
        
    }
    
    bool isUnivalTree(TreeNode* root) {
        theVal = root->val;
        return helper(root->left, theVal)&&helper(root->right, theVal);
    }
};