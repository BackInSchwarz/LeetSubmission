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
    TreeNode* lowestCommonAncestor(TreeNode* root, int & startValue, int& destValue) {
        if(!root) return NULL;
        if(root->val==startValue) return root;
        if(root->val==destValue) return root;
        TreeNode* l = lowestCommonAncestor(root->left, startValue, destValue);
        TreeNode* r = lowestCommonAncestor(root->right, startValue, destValue);
        if(l&&r) return root;
        return l?l:r;
    }
    
    bool getPath(TreeNode *root, int value, string &path) {
        if(!root) return false;
        if(root->val == value) return true;
        path += 'L';
        auto res = getPath(root->left, value, path);
        if(res) return true;
        path.pop_back();
        path += 'R';
        res = getPath(root->right, value, path);
        if(res) return true;
        path.pop_back();
        return false;
    }
    
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* LCA = lowestCommonAncestor(root, startValue, destValue);
        string p1, p2;
        getPath(LCA, startValue, p1);
        getPath(LCA, destValue, p2);
        for(auto &c : p1) c = 'U';
        return p1 + p2;
    }
};