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
    ListNode* middleNode(ListNode* head) {
        
        if (!head) return NULL;
        
        ListNode* ans = head;
        
        int n = 0;
        while(head){
            n++;
            head = head->next;
        }
        
        // cout<< "  n is :" <<n <<endl;
        
        int target = n/2;
        int cur = 0;
        
        
        while(cur!=target){
            // cout<<cur<<endl;
            cur++;
            ans = ans->next;
        }
        
        return ans;
    }
};