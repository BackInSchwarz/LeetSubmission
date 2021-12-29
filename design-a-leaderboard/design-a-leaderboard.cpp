class Leaderboard {
public:
    map<int, int> M;
    set<pair<int,int>> S;
    
    Leaderboard() {
        M.clear();
    }
    
    void addScore(int playerId, int score) {
        S.erase({M[playerId],playerId});
        M[playerId] += score;
        S.insert({M[playerId],playerId});
    }
    
    int top(int K) {
        int res = 0;
        int c = 0;
        for(auto it = S.rbegin(); it!=S.rend() && c < K; it++) {
            res+=(it->first);
            c++;
        }
        return res;
    }
    
    void reset(int playerId) {
        S.erase({M[playerId],playerId});
        M[playerId] = 0;
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */

