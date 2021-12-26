/**
 * Definition for a binary tree node.
 * struct Node {
 *     char val;
 *     Node *left;
 *     Node *right;
 *     Node() : val(' '), left(nullptr), right(nullptr) {}
 *     Node(char x) : val(x), left(nullptr), right(nullptr) {}
 *     Node(char x, Node *left, Node *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void dfs(Node* root, vector<int> & r){
        if (!root) return;
        
        
        if (isalpha(root->val))
            r[root->val -'a']++;
        
        dfs(root->left, r);
        dfs(root->right,r);
        
        return;
    }
    
    bool checkEquivalence(Node* root1, Node* root2) {
        
        vector<int> r1(26, 0), r2(26, 0);
        
        dfs(root1, r1);
        dfs(root2, r2);
        
        for (int i = 0 ; i<26; i++){
            if (r1[i]!=r2[i])
                return false;
        }
        
        return true;
    }
};