class Solution {
public:
    
    void dfs(vector<vector<char>>& board, int i, int j){
        if (i<0||i>board.size()-1) return;
        if (j<0||j>board[0].size()-1) return;
        
        if (board[i][j]=='X'||board[i][j]=='1') return;
        
        board[i][j]='1';
        
        dfs(board, i+1,j);
        dfs(board, i-1,j);
        dfs(board, i,j+1);
        dfs(board, i,j-1);
    }
    
    void solve(vector<vector<char>>& board) {
        int r = board.size();
        int c = board[0].size();
        
        // int i = 0;
        for (int j = 0;j<c;j++){
            if (board[0][j]=='O')
                dfs(board, 0,j);
            if (board[r-1][j]=='O')
                dfs(board, r-1,j);
        }

        for (int i = 0;i<r;i++){
            if (board[i][0]=='O')
                dfs(board, i,0);
            
            if (board[i][c-1]=='O')
                dfs(board, i,c-1);
        }

        for (int i =0;i<r;i++){
            for (int j=0;j<c;j++){
                if (board[i][j]=='O') board[i][j]='X';
                if (board[i][j]=='1') board[i][j]='O';
                
            }
        }
        
        
        return;
        
    }
};