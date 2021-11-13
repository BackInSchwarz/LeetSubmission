class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //bruteforce
        //for each day, find the next index where that day has higher temp than current day. n^2. 
        vector<priority_queue<int, vector<int>, greater<int>>> heapArr(100-30+1);
        vector<int> ans(temperatures.size(),0);
        for(int i =0;i<temperatures.size();i++){
            heapArr[temperatures[i]-30].push(i);
        }
        
        for(int i =0;i<temperatures.size();i++){
            int curInd=INT_MAX;
            // cout<<"i is "<<i<<endl;
            for(int j=temperatures[i]+1;j<=100;j++){
                // cout<<j<<endl;
                // cout<<heapArr[j-30].empty()<<endl;
                // // cout<<heapArr[j-30].empty()<<endl;
                while((heapArr[j-30].empty()!=true)&&(heapArr[j-30].top()<i)){
                    heapArr[j-30].pop();
                }
                if (heapArr[j-30].empty()!=true){
                    if (heapArr[j-30].top()>i){
                        curInd = min(curInd,heapArr[j-30].top());
                    }
                }
            }
            if (curInd!=INT_MAX) ans[i]=curInd-i;
        }
        
        return ans;
    }
};