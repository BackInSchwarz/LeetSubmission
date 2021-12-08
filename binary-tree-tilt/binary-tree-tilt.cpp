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
    int findSum(TreeNode* root){
        if(!root) return 0;
        return root->val+findSum(root->left)+findSum(root->right);
    }
    int findTilt(TreeNode* root) {
        //find the tilt of each node
        //sum it up
        //at the root, I need the sum of left tree and sum of right tree to calculate my tilt. I also need the tilt of the left tree and the right tree. 
        if(!root) return 0;
        int curTilt = abs(findSum(root->left)-findSum(root->right));
        return curTilt+findTilt(root->left) + findTilt(root->right);
    }
};