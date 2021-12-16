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
        stack<Node*> pstack;
        stack<Node*> qstack;
        while(p){
            pstack.push(p);
            p = p->parent;
        }
        
        while(q){
            qstack.push(q);
            q = q->parent;
        }
        
        Node* ans=NULL;
        
        while(!qstack.empty()&&!pstack.empty()){
            Node* curp = pstack.top();
            Node* curq = qstack.top();
            
            if (curp == curq){
                ans = curp;
                pstack.pop();
                qstack.pop();
                
            }else{
                break;
            }
            
        }
        
        return ans;
    }
};