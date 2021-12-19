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
    vector<int> postorder(Node* root) {
        if (!root) return {};
        vector<int> ans;
        for (auto child:root->children){
            vector<int> temp = postorder(child);
            for(auto item: temp){
                ans.push_back(item);
            }
        }
        
        ans.push_back(root->val);
        
        return ans;
    }
};