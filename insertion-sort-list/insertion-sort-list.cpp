/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode;
        ListNode* curr = head;
        
        while( curr ){
            
            ListNode* pre = dummy;
            
            while((pre->next!=NULL)&&(pre->next->val)<(curr->val)){
                pre = pre->next;
                // cout<<pre->val<<endl;
            }
            
            ListNode* next = curr->next;
            
            curr->next = pre->next;
            pre->next = curr;
            
            
            
            curr = next;
            
        }
        
        
        return dummy->next;
    }
};