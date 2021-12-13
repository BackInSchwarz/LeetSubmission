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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans(0);
        if(!root) return ans;
        
        vector<int> left =inorderTraversal(root->left);
        vector<int> right =inorderTraversal(root->right);
        for(auto item:left){
            ans.push_back(item);
        }
        ans.push_back(root->val);
        for(auto item:right){
            ans.push_back(item);
        }
        
        return ans;
    }
};