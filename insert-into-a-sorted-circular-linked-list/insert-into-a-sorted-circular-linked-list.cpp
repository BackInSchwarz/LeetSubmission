/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node* newNode = new Node(insertVal);
            // n==0 case
        if (!head){
            newNode->next = newNode;
            return newNode;
        }
        
        if((head->next)==(head)){
            newNode->next = head;
            head->next = newNode;
            return head;
        }
        //insertion intuition:
            //find the insertion spot
            //insert
        Node* fast= head->next;
        Node* slow= head;
        while(fast!=head){
            int slowVal = slow->val;
            int fastVal = fast->val;
            if(slowVal<=fastVal){
                if((slowVal<=insertVal)&&(insertVal<=fastVal)) break;
            }else{
                if(slowVal<=insertVal) break;
                if(insertVal<=fastVal) break;
            }
            fast = fast -> next;
            slow = slow -> next;
        }
        
        slow->next=newNode;
        newNode->next = fast;
        
        
        
        return head;
    }
};