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
    TreeNode* increasingBST(TreeNode* root) {
        if(!root) return NULL;
        
        TreeNode* l = increasingBST(root->left);
        TreeNode* r = increasingBST(root->right);
        TreeNode* ptr =l;
        // while(p)
        root->left = NULL;
        root->right = r;
        
        if(!l){
            return root;
        };
        
        while(ptr->right!=NULL){
            ptr = ptr->right;
        }
        ptr->right = root;
        
        
        return l;
        
    }
};