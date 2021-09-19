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
    void checkheight(int & height, int curh, TreeNode* root){
        if (root != NULL){
            curh+=1;
            if (curh>height)
                height = curh;
            checkheight(height, curh, root->left);
            checkheight(height, curh, root->right);
        }
            
    }
    bool isBalanced(TreeNode* root) {
        int lheight=0;
        int rheight=0;
        if (root==NULL) return true;
        checkheight(lheight, 0, root->left);
        checkheight(rheight, 0, root->right);
        cout<<lheight<<" "<<rheight;
        bool ans;
        if (abs(lheight-rheight)<=1){
            ans = isBalanced(root->left)
                &&isBalanced(root->right);
        }else{
            ans = false;
        }
        return ans;

    }
};