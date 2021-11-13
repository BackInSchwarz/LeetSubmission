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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {

        //n:= linked list length
        int n =0;
        ListNode* ptr = head;
        while(ptr!=NULL){
            n+=1;
            ptr = ptr->next;
        }
        //ans:= vector<ListNode*>(k)
        vector<ListNode*> ans(k);
        //lengthArr:= vector<int>(n/k) describes the length of each array. 
            // modulos = n%k, apply the 1 to first modulos indices of lenghtArr. 
        vector<int> nums(k, n/k);
        int remain = n%k;
        for (int i=0;i<remain;i++){
            nums[i]++;
            // cout<<nums[i]<<' ';
        }
        //find the head of each ListNode*
        ans[0]=head;
        ptr = head;
        for (int i=1;i<k;i++){
            cout<<i<<endl;
            if (nums[i]==0){
                ans[i]= NULL;
            }else{
                int cnt = nums[i-1];
                while(cnt>0){
                    if (cnt==1){
                        ListNode* temp =ptr->next;
                        ptr->next=NULL;
                        ptr= temp;

                    }else{
                        ptr = ptr->next;
                    }
                    cnt--;

                }
                ans[i] = ptr;
            }
        }
        
        return ans;
    }
};