class Solution {
public:
    bool bfs(vector<int>& arr, int start)
    {
        if(arr[start]==0)
            return true;
        arr[start]*=-1;
        int adj1=start+abs(arr[start]);
        if(adj1<arr.size()&&arr[adj1]>=0)
            if(bfs(arr,adj1))
                return true;
        int adj2=start-abs(arr[start]);
        if(adj2>=0&&arr[adj2]>=0)
            if(bfs(arr,adj2))
                return true;
        
        return false;
    }
    bool canReach(vector<int>& arr, int start) {
        return bfs(arr,start);
        
    }
};