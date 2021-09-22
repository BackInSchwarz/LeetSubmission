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
    void helper(TreeNode* root, vector<vector<int>> & answers, vector<int> answer, int targetSum){
        if (root == NULL) return;
        answer.push_back(root->val);
        if (root->left == NULL && root->right == NULL){
            if (root->val == targetSum){
                // answer.push_back(root->val);
                answers.push_back(answer);
            }   
        }else{
            
            if (root->left != NULL){
                // answer_push
                helper(root->left, answers, answer, targetSum - root->val);
            }
            
            if (root->right != NULL){
                // answer_push
                helper(root->right, answers, answer, targetSum - root->val);
            }
            
                
        }
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> answers;
        vector<int> answer;
        helper(root, answers, answer, targetSum );
        return answers;
    }
};