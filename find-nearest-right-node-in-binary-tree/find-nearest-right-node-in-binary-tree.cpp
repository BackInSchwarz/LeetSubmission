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
    bool found;
    int lv;
    TreeNode* ans;
    
    void helper(TreeNode* root, TreeNode* u, int curlv){
        if (!root) return;
        
        //find U
        if (root==u){
            found = true;
            lv = curlv;
            return;
        }
        
        //after U is found
        if (found&&!ans&&curlv ==lv){
            ans = root;
        }
        
        helper(root->left, u, curlv+1);
        helper(root->right, u, curlv+1);
        
        return;
    }
    
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        found = false;
        lv = 0;
        ans = NULL;
        
        helper(root, u, 0);
        
        return ans;
    }
};