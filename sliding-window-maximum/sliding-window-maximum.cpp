class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k==1) return nums;
        deque<int> dq;
        dq.push_back(0);
        for(int i=1;i<k-1;i++){
            // cout<<"initial"<<endl;
            // cout<<i<<endl;
            while (!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        vector<int> ans(nums.size()-k+1,0);
        for(int i=k-1;i<nums.size();i++){
            // cout<<"general"<<endl;
            // cout<<i<<endl;

            
            while (!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
            
            
            while (!dq.empty() && dq.front() < (i - k+1)) {
                
                dq.pop_front();
            }
            // cout<<"dq front "<<dq.front()<<endl;
            ans[i-k+1]=nums[dq.front()];
        }
        
        return ans;
    }
};