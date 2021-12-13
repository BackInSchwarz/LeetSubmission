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
    vector<int> ans;
    void helper(TreeNode* root){
        if(!root) return;
        if(root->left==NULL&&root->right!=NULL){
            ans.push_back(root->right->val);
        }
        if(root->right==NULL&&root->left!=NULL){
            ans.push_back(root->left->val);
        }
        helper(root->left);
        helper(root->right);
        return;
    }
    vector<int> getLonelyNodes(TreeNode* root) {
        ans.resize(0);
        helper(root);
        return ans;
    }
};