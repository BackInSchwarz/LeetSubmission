class Solution {
public:
    bool helper(vector<vector<char>> &board, string word, int x, int y, int curChar){
        // cout<<curChar<<endl;
        if (curChar>=word.length()) return true;
        
        int n = board.size();
        int m = board[0].size();
        
        bool ans = false;
        //initial case
        if (x==-1 && y == -1){

            for (int i = 0; i<n;i++)
                for (int j =0; j<m; j++){
                    if (word[curChar]==board[i][j]){
                        board[i][j] = '0';
                        ans = ans || helper(board, word, i, j, curChar+1);
                        // cout<<"next Call is "<<i<<" "<<j<<" "<<curChar+1<<endl;
                        board[i][j] = word[curChar];
                    }
                }
        }else{
            //general case
            // cout<<word[curChar]<<
            if ((x-1)>=0){
                // cout<<word[curChar]<<board[x-1][y]<<endl;
                if (word[curChar]==board[x-1][y]){
                    board[x-1][y] = '0';
                    ans = ans || helper(board, word, x-1, y, curChar+1);
                    board[x-1][y] = word[curChar];
                    
                }
            }
            if ((x+1)<n){
                // cout<<word[curChar]<<board[x+1][y]<<endl;
                if (word[curChar]==board[x+1][y]){
                    board[x+1][y] = '0';
                    ans = ans || helper(board, word, x+1, y, curChar+1);
                    board[x+1][y] = word[curChar];
                    
                }
            }
            if ((y-1)>=0){
                // cout<<word[curChar]<<board[x][y-1]<<endl;
                if (word[curChar]==board[x][y-1]){
                    board[x][y-1] = '0';
                    ans = ans || helper(board, word, x, y-1, curChar+1);
                    board[x][y-1] = word[curChar];
                    
                }
                
            }
            if ((y+1)<m){
                // cout<<word[curChar]<<board[x][y+1]<<endl;
                if (word[curChar]==board[x][y+1]){
                    board[x][y+1] = '0';
                    ans = ans || helper(board, word, x, y+1, curChar+1);
                    board[x][y+1] = word[curChar];
                    
                }            
            }
                
        }
        // cout<<"answer is "<<ans<<endl;
        return ans;
        
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        // int n = board.size();
        // int m = board[0].size();
        // //check if first word is there
        // for ()
        // //check if the neighbor word is there. 
        return helper(board,word, -1, -1, 0);
    }
};