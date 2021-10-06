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
//     vector<int> helper(TreeNode* root){
//         int maxSbranch = 0;
//         int maxFbranch = 0;
//         vector<int> ans{maxSbranch, maxFbranch};
        
//         if (root == NULL) return ans;
        
//         if ((root->left == NULL) and (root->right == NULL)){
//             ans[0] = root->val;
//             ans[1] = root->val;
//             return ans;
//         }else{
//             if ((root->left != NULL) and (root->right == NULL)){
//                 vector<int> l_ans = helper(root->left);
//                 ans[0] = l_ans[0] + root->val;
//                 ans[1] = (ans[0]>l_ans[1])?ans[0]:l_ans[1]; 
//                 return ans;
//             } 
//             if ((root->left == NULL) and (root->right != NULL)){
//                 vector<int> r_ans = helper(root->right);
//                 ans[0] = r_ans[0] + root->val;
//                 ans[1] = (ans[0]>r_ans[1])?ans[0]:r_ans[1]; 
//                 return ans;
//             } 
//             if ((root->left != NULL) and (root->right != NULL)){
//                 vector<int> l_ans = helper(root->left);
//                 vector<int> r_ans = helper(root->right);
//                 ans[0] = max(l_ans[0], r_ans[0]) + root->val;
//                 ans[1] = max(max(l_ans[1], r_ans[1]), l_ans[1] + r_ans[1] + root->val);
//                 return ans;
//             } 
//         }
        
        
//         return ans;
//     }
//     int maxPathSum(TreeNode* root) {
//         vector<int> ans = helper(root);
        
//         return max(ans[0],ans[1]);
//     }
    int max_sum=INT_MIN;
    int max_gain(TreeNode* root)
    {
        if(!root)return 0;
        int l=max(max_gain(root->left),0);
        int r=max(max_gain(root->right),0);
        int new_price=root->val+l+r;
        max_sum=max(max_sum,new_price);
        return root->val+max(l,r);
    }
    int maxPathSum(TreeNode* root) {
        max_gain(root);
        return max_sum;
    }
};