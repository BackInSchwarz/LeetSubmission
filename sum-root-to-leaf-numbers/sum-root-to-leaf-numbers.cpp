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
    
    void helper(TreeNode* root, int lastLevel){
        if (root == NULL) return;
        int curSum = lastLevel*10+ root->val;
        if (root->left==NULL && root->right==NULL){
            ans+=curSum;
        }else{
            if (root->left != NULL) helper(root->left, curSum);
            if (root->right !=NULL) helper(root->right, curSum);
        }
        return;
    }
    int sumNumbers(TreeNode* root) {
        ans = 0;
        helper(root, 0);
        return ans;
    }
};