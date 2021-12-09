class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, queue<int>> hm;
        int n = arr.size();
        if(n==1) return 0;
        //build hashmap
        for(int i=0;i<n;i++){
            hm[arr[i]].push(i);
            
        }
        // for(auto [key,val]:hm){
        //     for(auto item:val){
        //         cout<<key<<' '<<item<<endl;
        //     }
        // }
        //init
        
        queue<int> q;
        q.push(0);
        int steps=0;
        //loop
        while(!(q.empty())){
            //increment steps
            steps++;
            int numIter =q.size();
            // cout<<numIter<<endl;
            //get first one
            for(int i=0;i<numIter;i++){
                int ind = q.front();
                // cout<<ind<<endl;
                //add to explored
                int temp = arr[ind];
                arr[ind]=INT_MIN;
                //pop
                q.pop();
                //explore and check or push
                // queue<int> curQ = hm[temp];
                int curQ_size= hm[temp].size();
                for(int i=0;i<curQ_size;i++){
                    // cout<<item<<endl;
                    int item = hm[temp].front();
                    hm[temp].pop();
                    if(item!=ind){
                        if((item)==(n-1)) return steps;
                        //push to queue if not in explored
                        if(arr[item]!=INT_MIN) {
                            q.push(item);
                            // break;
                        }
                    }else{
                        hm[temp].push(item);
                    }
                }
                // cout<<i<<endl;
                if((ind+1)<n){
                    //check answer
                    if((ind+1)==(n-1)) return steps;
                    //push to queue if not in explored
                    if(arr[ind+1]!=INT_MIN) q.push(ind+1);
                }
                // cout<<i<<endl;
                if((ind-1)<n&&(ind-1)>=0){
                    //check answer
                    // if((ind+1)==(n-1)) return steps;
                    //push to queue;
                    if(arr[ind-1]!=INT_MIN) q.push(ind-1);
                }
                // cout<<arr[ind]<<endl;

            }


        }
        
        return steps;
    }
};