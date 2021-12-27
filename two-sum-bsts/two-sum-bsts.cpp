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
    
    unordered_set<int> r1;
    
    void dfs(TreeNode* root, int target){
        if (!root) return;
        
        r1.insert(target - (root->val));
        
        dfs(root->left, target);
        dfs(root->right, target);
        return;
    }
    
    bool findTarget(TreeNode* root){
        if (!root) return false;
        
        if(r1.find(root->val)!=r1.end()){
            return true;
        }
        
        return findTarget(root->left)|| findTarget(root->right);
    }
    
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        
        r1.clear();
        dfs(root1, target);
        
        return findTarget(root2);
    }
};