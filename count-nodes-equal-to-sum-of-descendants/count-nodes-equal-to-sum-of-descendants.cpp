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
    int cnt;
    
    long long decSum(TreeNode* root){
        if (!root) return 0;
        long long l = decSum(root->left);
        long long r = decSum(root->right);
        
        if ((l+r)==(root->val)) cnt++;
        
        return root->val + l + r;
    }
    
    int equalToDescendants(TreeNode* root) {
        cnt = 0;
        decSum(root);
        return cnt;
    }
};