/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
//         if (head == NULL) return false;
//         // if (head->next == NULL) return false;
//         map<ListNode*, bool> ht;
//         ht[head] = true;
//         while ((head->next)!=NULL){
//             // check if we can move on
//             if (ht.find(head->next)!=ht.end())
//                 return true;
//             // move on
//             ht[head->next] = true;
//             head = head->next;
//         }
        
//         return false;
        if (head==NULL) return false;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (slow!=NULL && fast != NULL && fast->next!=NULL){
            if (slow == fast)
                return true;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return false;
        
    }
};

