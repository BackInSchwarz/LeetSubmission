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
    
    vector<pair<int, int>> pairs;
    
    int getHeight(TreeNode* root){
        if (!root) return 0;
        
        int l = getHeight(root->left);
        int r = getHeight(root->right);
        
        int curH = 1 + max( l, r);
        
        pairs.push_back({curH, root->val});
        
        return curH;
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        pairs.clear();
        
        getHeight(root);
        
        sort(pairs.begin(), pairs.end());
        
        vector<vector<int>> ans;
        
        vector<int> curAns;
        int curH = 1;
        for(int i = 0; i<pairs.size(); i++){
            // height: pairs[i].first;
            // value: pairs[i].second;
            
            // cout<< "curH is: "<<pairs[i].first << " curVal is: "<< pairs[i].second<<endl;
            
            if (curH == pairs[i].first){
                curAns.push_back(pairs[i].second);
            }else{
                
                ans.push_back(curAns);
                curAns.clear();
                curH = pairs[i].first;
                
                curAns.push_back(pairs[i].second);

            }
        }
        
        ans.push_back(curAns);
        
        return ans;
    }
};