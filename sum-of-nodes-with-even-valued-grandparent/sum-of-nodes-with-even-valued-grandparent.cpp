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
    
    int helper(TreeNode* root, TreeNode* father, TreeNode* grandfather){
        if(!root) return 0;
        if(!grandfather) return helper(root->left, root, father) + helper(root->right, root, father);
        if(((grandfather->val)%2)==0)
            return root->val + helper(root->left, root, father) + helper(root->right, root, father);
        return helper(root->left, root, father) + helper(root->right, root, father);
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        return helper(root, NULL, NULL);
    }
};