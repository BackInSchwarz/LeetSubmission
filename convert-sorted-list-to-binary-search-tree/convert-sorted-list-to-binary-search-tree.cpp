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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        cout<<endl;
        int N = 0;
        ListNode* cnt = head;
        while (cnt!=NULL){
            N+=1;
            cnt = cnt->next;
        }
        cout<<N<<endl;
        if (N==0) return NULL;
        if (N==1) return new TreeNode(head->val);
        
        
        int mid = N/2+1;
        cnt = head;
        int ind = 1;
        ListNode* leftEnd = head; 
        while (ind<mid){
            cout<<ind <<" "<< mid<<endl;
            ind+=1;
            cnt = cnt->next;
            if (ind < mid )
                leftEnd = leftEnd->next;
        }
        TreeNode *root= new TreeNode(cnt->val);
        cout<<cnt->val<<endl;
        cout<<leftEnd->val<<endl;
        // root.val = cnt->val;
        //general case
        leftEnd->next = NULL;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(cnt->next);
        return root;
    }
};