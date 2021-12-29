/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    
    Node* first;
    Node* last;
    
    
    void dfs(Node* root){
        if(!root) return;
        
        dfs(root->left);
        
        if (!last){
            first = root;
        }else{
            last->right = root;
            root->left = last;
        }
        
        last = root;
        
        dfs(root->right);
        
        return;
        
    }
    
    Node* treeToDoublyList(Node* root) {
        
        if(!root) return NULL;
        
        first = NULL;
        last = NULL;
        
        dfs(root);
        
        last->right = first;
        first->left = last;
            
        
        return first;
    }
};