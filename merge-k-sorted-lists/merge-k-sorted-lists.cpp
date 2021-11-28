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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<vector<int>> pq;
        
        for(int i=0;i<lists.size();i++){
            if (lists[i]){
                pq.push({-(lists[i]->val), i});
                lists[i]=lists[i]->next;
            }
        }
        
        ListNode* ansHead=new ListNode();
        ListNode* ans = ansHead;
        while(!(pq.empty())){
            //pop and add
            // ListNode curNode;
            int val = -pq.top()[0];
            int ind = pq.top()[1];
            pq.pop();
            //push more if possible
            if (lists[ind]){
                pq.push({-(lists[ind]->val), ind});
                lists[ind]=lists[ind]->next;
            }
            // add the node
            ansHead->next = new ListNode(val);
            ansHead=ansHead->next;
        }
        
        return ans->next;
    }
};