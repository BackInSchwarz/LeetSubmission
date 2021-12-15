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
    
    int findBSTMax(TreeNode* root){
        if ( !root ) return INT_MAX;
        
        if ( !root->right ) return root->val;
        
        return findBSTMax( root->right );
    }
        
    int findBSTMin(TreeNode* root){
        if ( !root ) return INT_MAX;
        
        if ( !root->left ) return root->val;
        
        return findBSTMin( root->left );
    }
    
    int getMinimumDifference(TreeNode* root) {
        if(!root) return INT_MAX;
        
        int lmax = findBSTMax(root->left);
        int rmin = findBSTMin(root->right);
        
        int lMinDiff = getMinimumDifference(root->left);
        int rMinDiff = getMinimumDifference(root->right);
        
        int rootMinDiff = min(abs(lmax - root->val), abs( rmin - root->val ) );
        
        return min( min( lMinDiff, rMinDiff ), rootMinDiff );
    }
};