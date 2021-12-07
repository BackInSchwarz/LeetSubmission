class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans(boxes.length(),0);
        int n = boxes.length();
        int balls=0;
        int prev=0;
        for(int i =0;i<n;i++){
            ans[i]=balls+prev;
            prev = balls+prev;
            if(boxes[i]=='1') balls++;
            // prev = ans[i];
        }
        
        balls=0;
        prev=0;
        for(int i=n-1;i>=0;i--){
            ans[i]=ans[i]+balls+prev;
            prev = balls+prev;
            if(boxes[i]=='1') balls++;
            
        }
        
        return ans;
    }
};