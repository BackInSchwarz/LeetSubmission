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
    int Dia=-1;
    int helper(TreeNode* root){
        if (root == NULL) return 0;
        // update global max
        int l = helper(root->left);
        int r = helper(root->right);
        int curDia = 1 + r + l;
        if (curDia>Dia)
            Dia = curDia;
        // return longest path
        return 1 + max(l, r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        helper(root);
        
        return Dia-1;
    }
};