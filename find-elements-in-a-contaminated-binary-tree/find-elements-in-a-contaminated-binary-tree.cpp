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
class FindElements {
public:
    
    void fixTree(TreeNode* root){
        if (!root) return;
        
        if (root->left) root->left->val = (root->val)*2 + 1;
        if (root->right) root->right->val = (root->val)*2 + 2;
        
        fixTree(root->left);
        fixTree(root->right);
        return;
    }
    
    TreeNode* myroot;
    FindElements(TreeNode* root) {
        root->val = 0;
        fixTree(root);
        myroot = root;
        return;
    }
    
    
    bool findTarget(TreeNode* root, int target){
        if (!root) return false;
        
        if (root->val == target) return true;
        
        return findTarget(root->left, target) || findTarget(root->right, target);
    }
    
    bool find(int target) {
        
        return findTarget(myroot, target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */