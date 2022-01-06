class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> in(n+1);
        vector<vector<int>> out(n+1);
        vector<int> inCnt(n+1,0);
        for (auto& r:relations){
            in[r[1]].push_back(r[0]);
            inCnt[r[1]]++;
            out[r[0]].push_back(r[1]);
        }
        
        queue<pair<int, int>> q; // <course Number, start time of this course>
        vector<int> endTime(n+1,0); // end finished time of each course
        
        for (int i = 1; i<=n; i++){
            if (in[i].size() == 0){
                q.push({i, 0});
            }
        }
        
        int finished = 0;
        
        while(!q.empty()){
            int k = q.size();
            
            for ( int i = 0; i<k; i++){
                int cur = q.front().first;
                int curStartTime = q.front().second;
                q.pop();
                
                int curEndTime = curStartTime + time[cur-1];
                endTime[cur] = curEndTime;
                finished++;
                
                for (auto & nextCourse: out[cur]){
                    inCnt[nextCourse]--;
                    if (inCnt[nextCourse] == 0){
                        int StartTime = 0;
                        
                        for (auto & preCourse: in[nextCourse]){
                            StartTime = max(StartTime, endTime[preCourse]);
                        }
                        
                        q.push({nextCourse, StartTime});
                    }
                }
                
            }
        }
        
        if (finished != n)
            return -1;
        
        int ans = 0;
        for (auto & it:endTime){
            ans = max(ans, it);
        }
        
        return ans;
    }
};