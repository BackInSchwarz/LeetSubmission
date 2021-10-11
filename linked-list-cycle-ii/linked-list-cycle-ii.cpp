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
    // ListNode *detectCycle(ListNode *head) {
    //     if (head == NULL) return head;
    //     map<ListNode*, bool> ht;
    //     ht[head] = true;
    //     while ((head->next)!=NULL){
    //         if (ht.find(head->next)!=ht.end())
    //             return head->next;
    //         ht[head->next] = true;
    //         head = head->next;
    //     }
    //     return NULL;
    // }
    ListNode *detectCycle(ListNode *head) {
    if (head == NULL || head->next == NULL)
        return NULL;
    
    ListNode *slow  = head;
    ListNode *fast  = head;
    ListNode *entry = head;
    
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {                      // there is a cycle
            while(slow != entry) {               // found the entry location
                slow  = slow->next;
                entry = entry->next;
            }
            return entry;
        }
    }
    return NULL;                                 // there has no cycle
}
};

