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
    
    bool isSameTree( TreeNode* p, TreeNode* q ){
        if ( p && !q ) return false;
        if ( q && !p ) return false;
        if ( !p && !q ) return true;
        
        // cout << " checking p and q values: " << p->val << " "<< q->val <<endl;
        
        if ( p->val == q->val ) {
            
            // cout << p->val << endl;
            
            return isSameTree( p->left, q->left) && isSameTree( p->right, q->right);
        }
            
        
        return false;
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if ( !root ) return false;
        
        if ( root->val == subRoot->val ) {
            
            // cout << "Checking Subtree at Node value: " << root->val << endl;
            
            if ( isSameTree( root, subRoot ) ) return true;
            
        }
        
        
        return isSubtree( root->left, subRoot) || isSubtree( root->right, subRoot);
        
    }
};