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
    void checkDepth(int & height, int curh, TreeNode* root){
        if (root!=NULL){
            curh+=1;
            if (curh>height)
                height = curh;
            checkDepth(height, curh, root->left);
            checkDepth(height, curh, root->right);
        }
    }
    
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int lans = 1;
        int rans = 1;
        checkDepth(lans,1, root->left);
        checkDepth(rans,1, root->right);
        return max(lans, rans);
    }
};