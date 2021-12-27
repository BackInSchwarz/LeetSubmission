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
    int pseudoPalindromicPaths (TreeNode* root) {
        // using XOR to keep tracking of 1 and 0
        // use XOR to calculate on the fly
        // use (x & x-1) to reset right most 1 and consequently check if something is power of 2.
        
        int ans = 0;
        int curSum = 0;
        
        stack<pair<TreeNode*, int>> stk;
        stk.push({root, 0});
        
        while(!stk.empty()){
            TreeNode* curNode = stk.top().first;

            curSum = stk.top().second;
            stk.pop();
            
            if (!curNode) continue;


            
            curSum ^= 1<<(curNode->val);
            
//             cout<<" curNode_>val : "<< curNode->val<<endl;
//             cout<<" curSum : "<<curSum<<endl;
            
            if (!curNode->left && !curNode->right){
                if ( (curSum&(curSum-1)) == 0 ){
                    ans++;
                }
            }else{
                stk.push({curNode->left, curSum});
                stk.push({curNode->right, curSum});
            }
            
        }
        
        return ans;
    }
};