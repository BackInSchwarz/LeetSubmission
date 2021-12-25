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
    Node* findRoot(vector<Node*> tree) {
        int n = tree.size();
        
        if ( n == 1) return tree[0];
        
        unordered_set<Node*> inStk;
        unordered_map<Node*, Node*> parent;
        
        stack<Node*> stk;
        for (auto it:tree){
            stk.push(it);

        }
        
        while (!stk.empty()){
            Node* cur = stk.top();
            stk.pop();
            
            for (auto it: cur->children){
                if (inStk.find(it)==inStk.end()){
                    stk.push(it);
                    inStk.insert(it);
                }
                
                parent[it] = cur;
            }
        }
        
        Node * ans = tree[0];
        
        while (parent.find(ans)!=parent.end()){
            ans = parent[ans];
        }
        
        return ans;
    }
};