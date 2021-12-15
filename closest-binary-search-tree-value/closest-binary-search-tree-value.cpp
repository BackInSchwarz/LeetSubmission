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
    double diff;
    int ans;
    
    void helper( TreeNode* root, double target){
        if (!root) return;
        double curDiff = abs( root->val - target );
        // cout << curDiff << " " << abs( root->val - target ) << endl;
        if ( curDiff < diff ){
            ans = root->val;
            diff = curDiff;
        }
        
        helper( root->left, target);
        helper( root->right, target);
        
        return;
    }
    
    int closestValue(TreeNode* root, double target) {
        
        diff = 1000000001;
        ans = -1;
        
        helper( root, target );
        
        return ans;
    }
};