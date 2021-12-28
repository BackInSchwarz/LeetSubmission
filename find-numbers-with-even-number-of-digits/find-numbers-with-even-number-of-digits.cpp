class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        for (auto num: nums){
            int temp = log10(num)+1;
            // cout<<temp<<endl;
            if (temp%2==0)
                cnt++;
        }
        
        return cnt;
    }
};