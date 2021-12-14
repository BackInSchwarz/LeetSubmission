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
    int findDepth(TreeNode* root){
        if(!root) return 0;
        return 1+max(findDepth(root->left), findDepth(root->right));
    }
    
    int helper(TreeNode* root, int curLv, int maxLv){
        if (!root) return 0;
        if(!root->left&&!root->right&&curLv==maxLv) return root->val;
        
        return helper(root->left, curLv+1, maxLv) + helper(root->right, curLv+1, maxLv);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        int h = findDepth(root);
        return helper(root, 1, h);
    }
};