class Solution {
public:
    
    int findTrueVal(int label){
        int height = 0; //zero- indexed
        int temp = label;
        //find height
        while(temp!=1){
            height++;
            temp = temp/2;
        }
        
        // cout<< "label is: "<<label<<" height is : "<<height<< " true value is: "<<endl;
        
        if (height%2==0) return label;
        // cout<< " true value is: "<<(1<<height) + (1<<(height+1)) -1 - label<<endl;
        return (1<<height) + (1<<(height+1)) -1 - label;
    }
    
    vector<int> pathInZigZagTree(int label) {

        
        //find the true value;
        int truelabel = findTrueVal(label);
        
        int height = 0; //zero- indexed
        int temp = label;
        //find height
        while(temp!=1){
            height++;
            temp = temp/2;
        }
        
        vector<int> ans(height+1,0);
        ans[height] = truelabel;
        for (int i = height-1; i>=0;i--){
            ans[i] = ans[i+1]/2;
            // ans[i] = findTrueVal(ans[i]);
        }
        for (int i = height-1; i>=0;i--){
            ans[i] = findTrueVal(ans[i]);
            // ans[i] = findTrueVal(ans[i]);
        }
        
        ans[height] = label;
        
        return ans;
    }
};