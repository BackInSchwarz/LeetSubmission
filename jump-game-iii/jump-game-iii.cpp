class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        //create stack
        queue<int> q;
        // initialize
        q.push(start);

        unordered_set<int> explored;
        // loop through every nodes if reach the end return false
        while(!q.empty()){
            int n = q.size();
            // cout<<"current N size: "<<n<<endl;
            for(int i=0;i<n;i++){
                //check if it is answer
                int ind = q.front();
                q.pop();
                //add to explored
                explored.insert(ind);
                //validate
                if(ind<0||ind>=arr.size()) continue;
                if(arr[ind]==0) return true;
                //clean up the checked item

                //add stuff into queue if not in explored. 
                // cout<<
                if(explored.find(ind+arr[ind])==explored.end()){
                    q.push(ind+arr[ind]);
                    // cout<<ind+arr[ind]<<endl;
                } 
                if(explored.find(ind-arr[ind])==explored.end()) {
                    q.push(ind-arr[ind]);
                    // cout<<ind-arr[ind]<<endl;
                }

            }
        }
        
        return false;
    }
};