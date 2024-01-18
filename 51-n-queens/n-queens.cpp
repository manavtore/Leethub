class Solution {
public:
    bool isSafe(vector<string>& board,int row,int col,int& n){
         for(int i=0;i<row;i++){
             if(board[i][col]=='Q'){
                 return false;
             }
         }

         for(int i=row , j=col;i>=0 && j>=0;i-- ,j--){
             if(board[i][j]=='Q') return false;
         }

         for(int i=row ,j=col;i>=0 && j<n;i--,j++){
             if(board[i][j]=='Q') return false;
         }
         return true;

    }
    void solveNQueens(int& n,int row,vector<vector<string>>& ans,vector<string>& board){
        if(row==n){
            ans.push_back(board);
            return;
        }
        for(int col=0;col<n;col++){
            if(isSafe(board,row,col,n)){
                board[row][col]='Q';
                solveNQueens(n,row+1,ans,board);
                board[row][col]='.';
            }
        }
    }
  
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        solveNQueens(n,0,ans,board);
        return ans;
        
        }
    
};