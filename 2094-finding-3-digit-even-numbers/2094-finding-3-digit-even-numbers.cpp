class Solution {
public:
    unordered_set<int> ansSet;
    vector<int> ans;
    
    void helper(vector<int>& digits, int count, int curAns){
        if (count==3){
            if (curAns<100) return;
            if (curAns%2!=0) return;
            if (ansSet.find(curAns)!=ansSet.end()) return;
            ansSet.insert(curAns);
            ans.push_back(curAns);
            
            return;
        }
        
        int temp = 0;
        int cur =0;
        
        for (int i = 0; i < digits.size(); i++){
            
            if (digits[i]==-1) continue;
            
            temp = curAns*10 + digits[i];
            
            cur = digits[i];
            digits[i]=-1;
            
            helper(digits, count+1, temp);
            
            temp = 0;
            digits[i] = cur;
        }
        
        return;
    }
    
    vector<int> findEvenNumbers(vector<int>& digits) {
        // no leading zero: after 3 rounds need to be greater than 100.
        // even: check %2==0
        
        
        //declare
        
        
        
//         // sort
        
//         sort()
        
        // backtrack
        
        helper(digits, 0, 0);// 0 is the processed digits. 
        
        // put the set into array.
        // for (auto item: ansSet){
        //     ans.push_back(item);
        // }
        
        // sort the array.
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};