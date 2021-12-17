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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newNode = new TreeNode(val);
        if (!root) return newNode;
        
        if (!root->left&&!root->right){//is leaf

            if (val>(root->val)){
                root->right = new TreeNode(val);
            }else{
            //left
                root->left = new TreeNode(val);
            }
        }else{
            //is not leaf
            //right
            if (val>(root->val)){
                if (!(root->right)){
                    root->right = new TreeNode(val);
                }else{
                    root->right = insertIntoBST(root->right, val);
                }
                
            }else{
            //left
                if (!(root->left)){
                    root->left = new TreeNode(val);
                }else{
                    root->left = insertIntoBST(root->left, val);
                }
            }
               
        }
        
 
                
        return root;
    }
};