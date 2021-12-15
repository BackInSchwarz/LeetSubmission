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
    
    int helper ( TreeNode* root, int target ){
        
        if ( !root ) return -1;
        
        if ( root->val > target ) return root->val;
        
        int l = helper( root->left, target);
        
        int r = helper( root->right, target);   
        
        if ( (l != -1) && (r != -1) ) return min( l, r );
        
        return l==-1 ? r : l ;
        
        
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        
        if (!root) return -1;
        
        return helper ( root, root->val );
    }
};