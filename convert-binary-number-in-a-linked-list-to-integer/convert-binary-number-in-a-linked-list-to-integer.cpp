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
    int getDecimalValue(ListNode* head) {
        vector<int> bins;
        while(head){
            bins.push_back(head->val);
            head=head->next;
        }
        int n = bins.size();
        int ans = 0;
        for(int i=n-1;i>=0;i--){
            if(bins[i]==0) continue;
            ans+=1<<(n-1-i);
        }
        
        return ans;
    }
};