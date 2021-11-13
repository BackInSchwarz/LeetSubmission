class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        //need to find out the biggest square
        //need to start from n = 1 till biggest possible square. 
        //the results from last matrix is the input for the the next funciton. 
            //n==1, count number of ones. 
            //n==2, starting fromi=n-1, j=n-1, if [i-1][j-1] and [i-1][j] and [i][j-1] all equal to 1, [i][j]==1 and count+=1
        
        int r = matrix.size();
        int c = matrix[0].size();
        int n = min(r,c);
        int cnt = 0;
        // if (n==1){
        for(int i = 0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]==1) cnt+=1;
            }
        }
        // }
        vector<vector<int>> curmatrix = matrix;
        for(int k=2;k<=n;k++){
            for(int i=(k-1);i<r;i++){
                for(int j=(k-1);j<c;j++){
                    if((matrix[i-1][j-1]==1)&&(matrix[i-1][j]==1)&&(matrix[i][j-1]==1)&&(matrix[i][j]==1)){
                        curmatrix[i][j]=1;
                        cnt+=1;
                        // cout<<i<<" "<<j<<" "<<k<<endl;
                    }else{
                        curmatrix[i][j]=0;
                    }
                }
            }
            swap(curmatrix, matrix);
        }
        
        
        return cnt;

    }
};