// my solution;
// class Solution {
// public:
//     void solve(vector<vector<char>>& board) {
//         int r = board.size();
//         int c = board[0].size();
//         map<vector<int>, int> live;
//         vector<vector<int>> liveOrDead;
//         // vector<vector<int>> Dead;
//         for (int i = 0; i<r; i++){
//             for (int j = 0; j<c;j++){
//                 if (board[i][j] == 'O'){
//                     if (i==0 || i == (r-1)||j ==(0)||j ==(c-1))
//                         live[{i,j}]=1;
//                     else
//                         liveOrDead.push_back({i,j});
//                 }
//             }
//         }
//         for (auto item:liveOrDead){
//             vector<vector<int>> neis = {item, item, item, item};
//             neis[0][0] = neis[0][0]+1;
//             neis[1][0] = neis[1][0]-1;
//             neis[2][1] = neis[2][1]+1;
//             neis[3][1] = neis[3][1]-1;
//             bool survive = false;
//             for (auto nei:neis){
//                 if(live[nei]==1){
//                     live[item]=1;
//                     survive = true;
//                     break;
//                 }
//             }
//             if (survive == false){
//                 board[item[0]][item[1]] = 'X';
//             }
//         }
                    
//     }
// };

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        int row = board.size(), col = board[0].size();
        for (int i = 0; i < row; ++i) {
            check(board, i, 0);             // first column
            check(board, i, col - 1);       // last column
        }
        for (int j = 1; j < col - 1; ++j) {
            check(board, 0, j);             // first row
            check(board, row - 1, j);       // last row
        }
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '1') board[i][j] = 'O';
    }
    
    void check(vector<vector<char>>& board, int i, int j) {
        if (board[i][j] == 'O') {
            board[i][j] = '1';
            if (i > 1) check(board, i - 1, j);
            if (j > 1) check(board, i, j - 1);
            if (i + 1 < board.size()) check(board, i + 1, j);
            if (j + 1 < board[0].size()) check(board, i, j + 1);
        }
    }
};