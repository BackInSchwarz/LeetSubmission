/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        if (!root) return {};
        stack<Node*> stk;
        stk.push(root);
        vector<int> ans;
        
        while(!stk.empty()){
            Node* temp = stk.top();
            stk.pop();
            
            ans.push_back(temp->val);
            
            for (int i = (temp->children.size()-1); i>=0; i--){
                stk.push(temp->children[i]);
            }
        }
        
        return ans;
    }
};
    
