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

    unordered_map<int, int> hm;
    
    void helper( TreeNode* root) {
        
        if ( !root ) return;
        
        hm[root->val]++;
        
        helper( root->left );
        helper( root->right );
        
        return;
    }
    
    vector<int> findMode(TreeNode* root) {
        

        helper(root);
        
        vector<int> ans;
        
        int maxVal = INT_MIN;
        
        for ( auto & [ key, val ]: hm){
            if ( val > maxVal ) {
                maxVal = val;
                ans.clear();
                ans.push_back(key);
            }else{
                if ( val == maxVal ) {
                    ans.push_back( key );
                } else {
                    continue;
                }
            }
        }
        
        
        return ans;
    }
};