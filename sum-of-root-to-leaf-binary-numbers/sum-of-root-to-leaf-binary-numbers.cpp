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
    int helper(TreeNode* root, int pre){
        if(!root) return 0;
        int curSum = (pre<<1) + root->val;
        if(!root->left&& !root->right) return curSum;
        
        return helper(root->left, curSum) + helper(root->right, curSum);
    }
    int sumRootToLeaf(TreeNode* root) {
        return helper(root, 0);
    }
};