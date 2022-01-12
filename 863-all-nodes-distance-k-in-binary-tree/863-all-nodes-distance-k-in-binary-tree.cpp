/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        queue<TreeNode*> q;
        q.push(root);
        unordered_map<TreeNode*, TreeNode*> father;
        
        while(!q.empty()){
            int n = q.size();
            
            for ( int i = 0; i<n; i++){
                TreeNode* cur = q.front();
                q.pop();
                
                if (cur->left){
                    father[cur->left] = cur;
                    q.push(cur->left);
                }
                
                if (cur->right){
                    father[cur->right] = cur;
                    q.push(cur->right);
                }
            }
        }
        
        
        q.push(target);
        int dist = 0;
        
        unordered_set<TreeNode*> v;
        
        vector<int> ans;
        
        while( !q.empty()){
            int n = q.size();
            
            if (dist == k){
                
                for ( int i = 0; i<n ; i++){
                    TreeNode* cur = q.front();
                    q.pop();
                    ans.push_back(cur->val);
                }
                    
                return ans;
                
            }
            
            for ( int i = 0; i<n ; i++){
                TreeNode* cur = q.front();
                q.pop();
                v.insert(cur);
                
                if ( father.find(cur)!=father.end() && v.find(father[cur]) == v.end() ) q.push(father[cur]);
                
                if (cur->left && v.find(cur->left) == v.end()){
                    q.push(cur->left);
                }
                
                if (cur->right && v.find(cur->right) == v.end()){
                    q.push(cur->right);
                }
                
            }
            
            
            
            dist++;
        }
        
        
        return ans;
    }
};