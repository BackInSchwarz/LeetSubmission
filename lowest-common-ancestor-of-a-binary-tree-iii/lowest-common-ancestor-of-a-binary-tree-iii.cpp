/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        vector<Node*> p_list;
        vector<Node*> q_list;
        p_list.push_back(p);
        q_list.push_back(q);
        while(p){
            p_list.push_back(p->parent);
            p = p->parent;
        }
        
        while(q){
            q_list.push_back(q->parent);
            q = q->parent;
        }
        Node* ans=NULL;
        while((!q_list.empty())&&(!p_list.empty())&&(p_list.back()==q_list.back())){
            ans = p_list.back();
            p_list.pop_back();
            q_list.pop_back();
        }
        
        return ans;
    }
};