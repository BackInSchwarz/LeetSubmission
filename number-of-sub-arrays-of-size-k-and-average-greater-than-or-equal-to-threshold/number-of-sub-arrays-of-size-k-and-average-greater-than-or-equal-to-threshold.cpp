class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        if (n<k) return 0;
        int minSum = k* threshold;
        
        if (minSum ==0) return (n-k+1);//special case. 
        
        //general case. 
        //init case. 
        int curSum = 0;
        
        for (int i =0;i<k;i++){
            curSum+=arr[i];
        }
        
        int ans=0;
        
        if (curSum>=minSum) ans+=1;
        
        // regular case. 
        for (int i=k;i<n;i++){
            curSum = curSum + arr[i] - arr[i-k];
            if (curSum>=minSum) ans+=1;
        }
        
        return ans;
        
    }
};