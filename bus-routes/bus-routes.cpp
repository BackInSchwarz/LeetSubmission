class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        //Q: 
            //routes: routes representing bus routes
                //routes[i] is a bus route that the ith bus repeats forever. 
                    //if routes[0] = [1, 5, 7], this means that the 0th bus travels in the sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever.
            //you will start at the bus stop source
            //you want to go to the bus stop target.
            //You can travel between bus stops by buses only.
        //OUTPUT:
            //Return the least number of buses you must take to travel from source to target. 
            //Return -1 if it is not possible.
        //INPUT
            //vector<vector<int>>& routes 
                // routes[i][j] ith bus' jth stop
                // routes[i][j] is a bus stop
                //source starting bus stop
                //target ending bus stop
        //constraints
            // 1 <= routes.length <= 500. <-- number of buses can be 1 - 500
            // 1 <= routes[i].length <= 105. <- number of stops one bus can have.
            // All the values of routes[i] are unique. <- no duplicate stops for one bus
            // sum(routes[i].length) <= 105 <- there is at most 105 bus stops
            // 0 <= routes[i][j] < 106 <- bus stop number ranges from [0-106)
            // 0 <= source, target < 106 <- source and target will always in range. 
        
        // edge case
            //case 1: no answer because no buses arrives at the source/target station
                // if (source not in any routes) return -1;
                // if (target not in any routes) return -1;
            //case 2: no answer because no routes
            //case 3: least steps of route is round <- BFS is very helpful
        
        //thought
            //steps
                //steps 1: search each routes and see which of the buses stop at the source. 
                    //search or hashmap?
                        //search: 
                            //n*log(average(k)) for each explore
                            // n*average(k)*n*log(average(k)) = n^2 * avg(k) * log(avg(k)) for worst case(go through every nodes)
                        //hashmap
                            // n*average(k) overhead
                            // o(1) for each explore.
                    //how to document explored?
                        //change value in source: 
                            //result: then asending order is broken. Searching is not possible
                        //store the searched nodes in a hashmap.
                            //O(1) time to check if one is explored. 
                    //how do we explore?
                        //busStopMap[stopNumber]=vector<int> ListOfBuses i and its index in the route j.
                        //for each bus, 
                            //check last stop
                                //is it explored? check vistes[i][j]
                                    //yes: continue
                                    //no: push it to the task queue
                            //check next stop
                                //same as above.
                    //
        unordered_map<int, vector<int>> to_routes;
        int S = source;
        int T = target;
        for (int i = 0; i < routes.size(); ++i)
            for (int j : routes[i])
                to_routes[j].push_back(i);
        queue<pair<int, int>> bfs;
        bfs.push({S, 0});
        unordered_set<int> seen = {S};
        while (!bfs.empty()) {
            int stop = bfs.front().first, bus = bfs.front().second;
            bfs.pop();
            if (stop == T)
                return bus;
            for (int i : to_routes[stop]) {
                for (int j : routes[i]) {
                    if (seen.find(j) == seen.end()) {
                        seen.insert(j);
                        bfs.push({j, bus + 1});
                    }
                }
                routes[i].clear();
            }
        }
        return -1;
    }
};