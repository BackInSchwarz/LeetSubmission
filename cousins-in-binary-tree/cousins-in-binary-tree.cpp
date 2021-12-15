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
    TreeNode* xParent;
    TreeNode* yParent;
    int xLv;
    int yLv;
    
    void helper(TreeNode* root, TreeNode* father, int x, int y, int curLv){
        
        if ( !root ) return;
        
        if ( root->val == x ){
            xLv = curLv;
            xParent = father;
        }

        if ( root->val == y ){
            yLv = curLv;
            yParent = father;
        }
        
        helper( root->left, root, x, y, curLv+1 );
  
        helper( root->right, root, x, y, curLv+1 );
        
        
        return;
        
        
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        xParent = NULL;
        yParent = NULL;
        xLv = 0;
        yLv = 0;
        
        helper(root, NULL, x, y, 1);
        
        if ((xParent != yParent) && ( xLv == yLv))
            return true;
        
        return false;
    }
};