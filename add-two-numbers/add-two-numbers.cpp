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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n1=0;
        int n2=0;
        ListNode* head=l1;
        while(head!=NULL){
            head=head->next;
            n1++;
        }
        head=l2;
        while(head!=NULL){
            head=head->next;
            n2++;
        }
        
        ListNode* ansHead = new ListNode();
        ListNode* ans = ansHead;
        int n = max(n1,n2)+1;
        int carry=0;
        for (int i=0;i<n;i++){
            // int carry = 0;
            int val=carry;
            if(l1!=NULL) val+=l1->val;
            if(l2!=NULL) val+=l2->val;
            if((val/10)>=1){
                val=val%10;
                carry=1;
            }else{
                carry=0;
            }
            if ((i==(n-1))&&(val==0)) break;
            ansHead->next = new ListNode(val);
            if(l1!=NULL) l1=l1->next;
            if(l2!=NULL) l2=l2->next;
            ansHead = ansHead->next;
            
        }
        
        return ans->next;
        
        
    }
};